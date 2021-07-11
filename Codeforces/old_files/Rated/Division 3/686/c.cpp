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

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n+1];
        FOR(i, 1, n+1) cin>>a[i];
        //find minimum number of gaps for any value ai
        map<int, int> lastseen; // <val, index>
        vi ans(n+1, 0);
        FOR(i, 1, n+1){
            if(lastseen[a[i]]!=i-1) ans[a[i]]++;
            lastseen[a[i]]=i;
        }
      //  cout<<"ok"<<endl;
          int mn=(int)2e5;
        for(int j=1; j<=n; j++){
            int i=a[j];
            if(a[n]!=i) ans[i]++;
            mn=min(mn, ans[i]);
        }
       cout<<mn<<endl;



    }
return 0;
}
