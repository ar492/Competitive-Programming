#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
int t=0;
cin>>t;
for(int i=0;i<t;i++){
    double a,b,c; cin>>a>>b>>c;///a = how much for 1 donut, b donuts cost c dollars
    int p1, p2;
    if(a>=c){cout<<"-1 "<<(ll)b<<endl;}
    else if (a<c){
        if(c/b<a){cout<<"1 "<<(ll)b<<endl;}
        else if(c/b>=a){cout<<"1 -1"<<endl;}
    }///4 5 20
    ///4 6 20
    ///4 4 20
    ///4 3 20
}
return 0;
}
