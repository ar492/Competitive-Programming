#include <bits/stdc++.h>
using namespace std;

vector<int> a, p; int n;
bool test(int x){
    for(int i=x-1; i<n; i++){
        int k;
        i==x-1 ? k=p[i] : k=(p[i]-p[i-x])%7;
        if(k%7==0) return true;
    }
    return false;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    //ifstream cin("div7.in"); ofstream cout("div7.out");
    cin>>n;
    a.resize(n); p.resize(n);
    for(int i=0; i<n; i++){
        int u; cin>>u;
        a[i]=u%7;
        i==0 ? p[i]=a[i] : p[i]=(p[i-1]+a[i])%7;
    }
    int l=1; int r=n; int m=0; int res=0;
    while(l<=r){
        m=(l+r)/2;
        if(test(m)){
            l=m+1;
            res=m;
        }
        else r=m-1;
    }
    cout<<res<<endl;
return 0;
}
