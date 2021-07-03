///time limit exceeded
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
ifstream fin("candy.in");
ofstream fout("candy.out");
int num=0; int answer=-1;

bool check(int x)
{
   if(x==0)
   return false;

   return (ceil(log2(x)) == floor(log2(x)));
}
void fillxvec(int num)
{
    if (num%2==1){
    for (int i=1; i<=num/2+1; i+=2)
    {
        if (num%i==0){
            if (check(num/i + 1)==true){
            answer=i;
            }
        }
        if (answer!=-1){break;}
    }
    cout<<answer<<endl;
    }
    else if (num%2==0){
    for (int i=2; i<=num/2+1; i+=2)
    {
        if (num%i==0){
            if (check(num/i + 1)==true){
            answer=i;
            }
        }
        if (answer!=-1){break;}
    }
    cout<<answer<<endl;
    }
}
int main() {
int t=0; fin>>t;
int num=0;
for (int i=0; i<t; i++){
  fin>>num;
  fillxvec(num);
  answer=-1;
}
return 0;
}
