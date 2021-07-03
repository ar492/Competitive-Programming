/*
notice that bessie always goes from node with smaller quality
to a node with larger quality. this is a clue to use dp.
sort the nodes l to g by quality. dp[i] is the maximum
energy at node i (after eating node i). start from the node with
least qualiy -> node with highest quality, name the current node i.
initialize dp[i] to be dp[quality of i]. then iterate over all j such
that quality[j] < quality[i], and do dp for traveling from j to i.
do dp[i]=max(dp[i], dp[j] + e*distance(i, j) + qual[i]
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define qual first
#define ID second

const int sz = 1001;
int n, e;
vector<int> a[sz];
int SP[sz][sz];
int DP[sz];
pair<int, int> qual[sz];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("buffet.in", "r", stdin);
    freopen("buffet.out", "w", stdout);
    cin >> n >> e;
    fill(DP + 1, DP + n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        int d;
        cin >> qual[i].qual >> d;
        qual[i].ID = i;
        for(ll j = 0; j < d; j++)
        {
            int u;
            cin >> u;
            a[i].push_back(u);
        }
    }
    for(int i = 1; i <= n; i++) //starting node
    {
        queue<ll> q;
        vector<bool> v(n + 1, 0);
        q.push(i);
        v[i] = 1;
        vector<int> d(n + 1, 0);
        while(!q.empty())
        {
            for(int j : a[q.front()])
            {
                if(!v[j])
                {
                    d[j] = d[q.front()] + 1;
                    SP[i][j] = d[j];
                    q.push(j);
                    v[j] = 1;
                }
            }
            q.pop();
        }
        fill(v.begin(), v.end(), 0);
    }
    sort(qual + 1, qual + 1 + n); //sort by qualities
    for(int i = 1; i <= n; i++)
    {
        int endup = qual[i].ID;
        DP[endup] = qual[i].qual;
        for(int j = 1; j < i; j++)
        {
            int start = qual[j].ID;
            if(SP[start][endup]==0) continue; // I MISSED THIS ORIGINALLY... if there is no path between them, dont do DP
            int edgeloss = e * SP[start][endup];
            DP[endup] = max(DP[endup], DP[start] - edgeloss + qual[i].qual);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, DP[i]);
    }
    cout << ans << endl;
    return 0;
}
