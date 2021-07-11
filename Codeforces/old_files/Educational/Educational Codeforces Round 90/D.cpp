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

int main(){

    TCASES{
        int n; cin>>n;
        vll PO(n, 0), PE(n, 0), a(n, 0); //rmbr to do edge case
        FOR(i, 0, n) cin>>a[i];
        ll sum=accumulate(all(a), 0, plus<ll>());
        for(int i=1; i<n; i++) a[i]+=a[i-1];
        PE[0]=a[0];
        FOR(i, 1, n){
            if(i%2==0){
                PE[i]=PE[i-1]+a[i];
                PO[i]=PO[i-1];
            }
            else{
                PO[i]=PO[i-1]+a[i];
                PE[i]=PE[i-1];
            }
        }
        vpll f(n, {0, 0});
        FOR(i, 0, n){
            if(i==0) f[i]={PO[0]-PE[0], 0};
            else{
                ll c=PO[i]-PE[i];
                if(c<f[i-1].fi) f[i]={c, i};
                else f[i]={c, f[i-1].se};
            }
        }
        vpll s(n, {1e14, 0});
        FOR(i, 0, n){
            if(i==0) s[i]={PO[0]-PE[0], 0};
            else{
                ll c=PO[i]-PE[i];
                if(c>s[i-1].fi) s[i]={c, i};
                else f[i]={c, s[i-1].se};
            }
        }
        ll ans=0, mx=0;
        FOR(i, 1, n){
            mx=max(mx, f[i].fi-s[i-1].fi);
        }
        FOR(i, 1, n){
            if(mx==f[i].fi-s[i-1].fi){
                ans=sum-(a[f[i].se]-a[s[i-1].se])+f[i].fi-s[i-1].fi;
            }
        }
        ans=max(ans, a[n-1]);
        FOR(i, 1, n){
            ans=max(ans, PO[i]-PE[i]+a[n-1]-a[i]);
        }
        print(ans)

    }
    return 0;
}
