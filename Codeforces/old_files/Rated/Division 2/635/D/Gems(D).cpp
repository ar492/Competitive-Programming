#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

ifstream fin("gems.in");
ofstream fout("gems.out");

struct Dist{
    long long int D;
    long long int calc=0;
    long long int x, y, z;
};
vector <Dist> acc;
vector <Dist> finals;
void swap(long long int *xp, long long int *yp)
{
   long long int temp = *xp;
   *xp = *yp;
   *yp = temp;
}
void bubbleSort(long long int arr[], long long int n)
{
  long long int i, j;
  bool swapped;
  for (i = 0; i < n-1; i++)
  {
    swapped = false;
    for (j = 0; j < n-i-1; j++)
    {
       if (arr[j] > arr[j+1])
       {
          swap(&arr[j], &arr[j+1]);
          swapped = true;
       }
    }
    if (swapped == false)
       {break;}
  }
}

long long int distance(long long int a, long long int b, long long int c){
     long long int ans=(abs(a-b)+abs(b-c)+abs(a-c));
     Dist d; d.x=a; d.y=b; d.z=c; d.D=ans;
     acc.push_back(d);
     return ans;
}

void isort(){
   for (long long int x=0; x<acc.size(); x++){
   for (long long int y=x; y<acc.size(); y++){
       if (x!=y){
           if (acc[x].D>acc[y].D){
               Dist temp=acc[x];
               acc[x]=acc[y];
               acc[y]=temp;
           }
       }
   }
   }
}
void isort2(){
   for (long long int x=0; x<finals.size(); x++){
   for (long long int y=x; y<finals.size(); y++){
       if (x!=y){
           if (finals[x].calc>finals[y].calc){
               Dist temp=finals[x];
               finals[x]=finals[y];
               finals[y]=temp;
           }
       }
   }
}
}
int main() {
    long long int t=0;
    long long int nr, ng, nb=0;
    fin>>t;
    for (long long int i=0; i<t; i++)
    {
         fin>>nr>>ng>>nb;
         long long int red[nr]; long long int green[ng]; long long int blue[nb];
         for (long long int j=0; j<nr; j++){fin>>red[j];}
         bubbleSort(red, nr);
         for (long long int j=0; j<ng; j++){fin>>green[j];}
         bubbleSort(green, ng);
         for (long long int j=0; j<nb; j++){fin>>blue[j];}
         bubbleSort(blue, nb);
          if (nr==1 && ng==1 && nb==1){
            long long int x=red[0]; long long int y=green[0]; long long int z=blue[0];
            long long int p;
            ///p=pow(x-y, 2)+pow(y-z, 2)+pow(z-x, 2);
            p=(x-y)*(x-y)+(y-z)*(y-z)+(z-x)*(z-x);
            fout<<p<<endl;
            }
          else{
             for (long long int q=0; q<nr; q++){
                for (long long int r=0; r<ng; r++){
                    for (long long int s=0; s<nb; s++){
                        long long int x=distance(red[q], green[r], blue[s]);
                 }
               }
             }
             isort();
            if (acc[0].D!=acc[1].D){
               acc[0].calc=pow(acc[0].x-acc[0].y, 2)+pow(acc[0].y-acc[0].z, 2)+pow(acc[0].z-acc[0].x, 2);
               finals.push_back(acc[0]);
            }
            else if (acc[0].D==acc[1].D){
                bool check=false;
                for (int g=0; g<acc.size(); g++)
                {
                  if (acc[g].D==acc[g+1].D)
                  {
                    acc[g].calc=pow(acc[g].x-acc[g].y, 2)+pow(acc[g].y-acc[g].z, 2)+pow(acc[g].z-acc[g].x, 2);
                    finals.push_back(acc[g]);
                  }
                  else if (acc[g-1].D==acc[g].D){
                    acc[g].calc=pow(acc[g].x-acc[g].y, 2)+pow(acc[g].y-acc[g].z, 2)+pow(acc[g].z-acc[g].x, 2);
                    finals.push_back(acc[g]);
                  }
                }
                 isort2();
            }
             fout<<finals[0].calc<<endl;
             finals.clear();
             acc.clear();
        }
    }
    return 0;
}
