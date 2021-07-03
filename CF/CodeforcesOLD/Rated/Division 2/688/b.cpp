
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
void printv(vector<ll> v, int sz)
{
    for(int i = 0; i < sz; i++)
        cout << v[i] << " ";
    cout << "\n";
}

void exe(ll n)
{
    vll a(n);
    FOR(i, 0, n) cin >> a[i];
    ll ans = 0;
    vll rights(n, 0);
    for(int i = n - 2; i >= 0; i--)
    {
        ans += abs(a[i + 1] - a[i]);
    }
    ll mxsub = max(abs(a[1] - a[0]), abs(a[n - 1] - a[n - 2]));
    FOR(i, 1, n - 1)
    {
        mxsub = max(mxsub, abs(a[i] - a[i + 1]) + abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i - 1]));
    }
    cout <<ans - mxsub << endl;
}
int main()
{
    TCASES
    {
        ll n;
        cin >> n;
        exe(n);
    }
    return 0;
}
