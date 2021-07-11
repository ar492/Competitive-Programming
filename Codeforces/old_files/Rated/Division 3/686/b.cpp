#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
#define fi first
#define se second

//vectors
using vi = vector<int>;
using vpii = vector<pii>;
using vpll = vector<pll>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define sort(x) sort(all(x)) //type out sorting for arrays
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); i++)


void exe(){
    int n; cin>>n;
    int a[n]; vector<int> f(n+1, 0);
    map<int, int> mp;
    FOR(i, 0, n){ cin>>a[i]; f[a[i]]++; mp[a[i]]=i; }
    FOR(i, 1, n+1){
        if(f[i]==1){
            cout<<mp[i]+1<<endl;
            return;
        }
    }
    cout<<-1<<endl; return;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        exe();

    }
return 0;
}
