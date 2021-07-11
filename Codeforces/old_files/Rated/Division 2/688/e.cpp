
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
#define fi first
#define se second

//vectors
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define all(x) (x).begin(), (x).end()
#define sort(x) sort(all(x)) //type out sorting for arrays
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define TCASES int testcases; cin>>testcases; while(testcases--)

#define print(x) cout<<x<<"\n";
void printv(vector<ll> v, int sz){
    for(int i=0; i<sz; i++)
        cout<<v[i]<<" ";
    cout<<"\n";
}

const int sz=(int)2e5+1;
bool eaten[sz];
vi a[sz];

void dfs(int u, int d, int k){
    if(d>k) return;
    eaten[u]=1;
    int ne=a[u].size();
    for(int i:a[u]){
        if(ne<k) return;
        dfs(i, d+1, k);
        ne--;
    }
}
bool ok(int k){
    dfs(1, k);
}
void reset(int n){
    FOR(i, 1, n+1){
        eaten[i]=0;
        a[i].clear();
    }
}
int main(){

    TCASES{
        int n; cin>>n;
        FOR(i, 0, n){
            int u,v; cin>>u>>v;
            a[u].pb(v);
            a[v].pb(u);
        }
        int l=0, r=n-1, ans;
        while(l<=r){
            int m=(l+r)/2;
            if(ok(m)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
            FOR(i, 1, n+1){
                eaten[i]=0;
            }
        cout<<ans<<endl;
        reset(n);
    }
return 0;
}
