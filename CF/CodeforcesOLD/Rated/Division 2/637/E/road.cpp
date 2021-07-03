#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("road.in");

int time=0;
int n,m,g,r;
int rg;
int loc=0;
void execute(int safety[])
{
    if (time==0){rg=g;}
    if (safety[loc+])
}
int main(){
fin>>n>>m;
int safety[n];
for (int i=0; i<n; i++){safety[i]=0;}
for (int i=0; i<m; i++){
    int temp;
    fin>>temp;
    safety[temp]=1;;
}
fin>>g>>r;
for (int i=0; i<n; i++){cout<<safety[i]<<endl;}
execute(safety);
return 0;
}
