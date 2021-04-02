// https://www.spoj.com/problems/INVCNT/
#include<bits/stdc++.h>
using namespace std;

const int sz=1e7+1;
int bit[sz], n;

void update(int pos, int val){
        for(; pos<sz; pos+=pos&-pos)
                bit[pos]+=val;
}
int getsum(int x, int sum=0){
        for(; x>0; x-=x&-x) sum+=bit[x];
        return sum;
}
int sum(int a, int b){
        return(getsum(b)-getsum(a-1));
}

int main(){
        int t; cin>>t;
        while(t--){
                cin>>n;
                int a[n+1];
                for(int i=1; i<=n; i++) cin>>a[i];
                long long ans=0;
                for(int i=n; i>=1; i--){
                        update(a[i], 1);
                        ans+=sum(1, a[i]-1);
                }
                cout<<ans<<endl;
                for(int i=1; i<=n; i++) update(a[i], -1);
        }
        return 0;
}
