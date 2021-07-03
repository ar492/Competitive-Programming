#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
ifstream fin("balance.in");
ofstream fout("balance.out");

void execute(int n){
    int sum=(n/2)*(n/2+1);
    int sum2=(n/2)*(n/2);
    int change=(n/2)*2-1+sum-sum2;
    for (int i=0; i<n/2-1; i++){cout<<2*i+1<<" ";}
    cout<<change<<endl;
}
int main(){
int t=0; fin>>t;
int n=0;
for (int i=0; i<t; i++){
  fin>>n;
  if ((n/2)%2!=0){cout<<"NO"<<endl;}
  else{
    cout<<"YES"<<endl;
    for (int i=1; i<=n/2; i++){cout<<2*i<<" ";}
    execute(n);
  }
}
return 0;
}
