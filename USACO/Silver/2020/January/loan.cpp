#include <bits/stdc++.h>
using namespace std;

long long n,k,m;
void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("loan.in","r",stdin);
    freopen("loan.out","w",stdout);
   cin>>n>>k>>m;
}

bool bs(long long x){
    //cout<<"called for "<<x<<endl;
    long long g=0;
    long long done=0;
    while(done<k){
       if(max((n-g)/x, m)==m){
            if((k-done)*m+g >= n) return true;
            else return false;
       }
       long long value=(n-g)/x;
       done+=((n-value*x)-(g))/value+1;
       g+=(((n-value*x)-(g))/value+1)*value;
    }
    return(g>=n);
}

int main(){
    setup();
    long long l=1, r=n/m+1;
    long long ans;
    while(l<=r){
        long long x=(l+r)/2;
        if(bs(x)){
            ans=x;
            l=x+1;
        }
        else r=x-1;
    }
    cout<<ans<<endl;
return 0;
}
