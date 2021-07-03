
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



int main()
{
    TCASES
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, m) cin >> b[i];
        int cnt = 0;
        for(int i : a)
        {
            for(int j : b)
            {
                if(i == j)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
