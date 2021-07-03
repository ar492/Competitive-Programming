#include <bits/stdc++.h>
using namespace std;

long long exe(int a, int b, int x, int y, int n){//guaranteed a>=b
    int t=min(n, b-y);
   // cout<<"subtracting "<<t<<" from "<<b<<endl;
    b-=min(n, b-y);
    n-=t;
    //cout<<"subtracting "<<min(n, a-x)<<" from "<<a<<endl;
    a-=min(n, a-x);
    return((long long)a * (long long)b);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int a,b,x,y,n; cin>>a>>b>>x>>y>>n;
        cout<<min(exe(a,b,x,y,n), exe(b,a,y,x,n))<<endl;
    }

return 0;
}
/*
1
10 11 2 1 5
*/
