#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

ifstream fin("balance.in");

int main(){
int t=0;
fin>>t;
int n=0;
for (int i=0; i<t; i++){
    fin>>n;
    if (n!=2){
    ll x=(n/2)-1;
    ll y=pow(2,n)+pow(2,x+1)-2;
    //cout<<(ll)pow(2,n+1)-2-y<<" and "<<y<<endl;
    cout<<(ll)abs(pow(2,n+1)-2-2*y)<<endl;
    }
    else{cout<<2<<endl;}
}

return 0;
}
