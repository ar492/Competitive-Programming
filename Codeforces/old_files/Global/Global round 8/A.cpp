#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

ifstream fin("input.in");

int main(){
int t=0;
fin>>t;
for(int w=0; w<t; w++){
    ll a, b, n;
    fin>>a>>b>>n;
    int counter=0;
    if(a>b){swap(a,b);}
    while(a<=n && b<=n){
        if(a>b){swap(a,b);}
        ///cout<<a<<" += "<<b<<endl;
        a+=b;
        ///cout<<"(a,b)=("<<a<<","<<b<<")"<<endl;
        ///swap(a,b);
        ///cout<<"a>b, swap(a,b): a="<<a<<", b="<<b<<endl;
        counter++;
        if(a>n || b>n){break;}

        ///cout<<b<<" += "<<a<<endl;
        b+=a; counter++;
       /// cout<<"(a,b)=("<<a<<","<<b<<")"<<endl;

    }
    cout<<counter<<endl;
}
return 0;
}
