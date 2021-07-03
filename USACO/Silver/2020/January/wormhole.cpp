//https://usaco.guide/solutions/usaco-992
/*
#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5;

vector<pair<int, int>> g[MX]; //neighbor location, weight
vector<int> ar(MX), component(MX);
int n, m;

void dfs (int v, int label, int minW) {
    component[v] = label;

    for (auto x: g[v]) {
        if (x.second < minW || component[x.first] != -1) continue;
        dfs (x.first, label, minW);
    }
}

bool ok (int minW) {
    fill (component.begin(), component.end(), -1);
    int label = -1;

    for (int i = 0; i < n; i++) {
        if (component[i] != -1) continue;
        dfs(i, ++label, minW);
    }

    for (int i = 0; i < n; i++) {
        if (component[i] != component[ar[i]]) return false;
    }

    return true;
}

int main () {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ar[i]--;
    }

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        g[a].push_back(make_pair(b, w));
        g[b].push_back(make_pair(a, w));
    }

    int sol = -1;
    int lo = 1, hi = 1e9 + 1;
    int top = hi;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;

        if (ok(mid)) {
            sol = max (sol, mid);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << (sol == top ? -1 : sol) << '\n';
}
*/
///DSU

//control+option+n to run!
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define FOR(i, a, b) for (signed long long i = (signed long long)(a); i < (signed long long)(b); i++)
#define NEGFOR(i, a, b) for (ll i = (a); i > (b); i--)
#define vll vector<long long>
#define sll set<long long>
#define ld long double
#define inf 1000000000000000000
#define mll multiset<long long>
#define vpll vector<pll>
#define nn << "\n"
#define ss << " "
#define F(i, b) for (ll i = 0; i < b; i++)

vll parent(1000000),sz(1000000);
void make_set(ll v) {
    parent[v] = v;
    sz[v] = 1;
}
ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void unite(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    ifstream cin("wormsort.in");
   // ofstream cout("wormsort.out");

    clock_t tStart = clock();
    ll n,m; cin>>n>>m;
    vll v(n);
    FOR(i,0,n) cin>>v[i];
    vll sorted=v;
    vector <pair <ll,pll>> edges;
    FOR(i,0,m){
        ll a,b,c; cin>>a>>b>>c;
        edges.pb({c,{a,b}});
    }
    sort(edges.rbegin(),edges.rend()); //g to l
    FOR(i,0,n){
        make_set(i+1);
    }
    sort(sorted.begin(),sorted.end());

    vpll check;

    FOR(i,0,n){
        if (sorted[i]!=v[i]){
            check.pb({sorted[i],v[i]});
        }
    }
    if(check.size()==0) {cout<<-1; return 0;}
    for(auto i: edges){
        ll a=i.second.first,b=i.second.second;

        if (find_set(a)!=find_set(b)){
            unite(a,b);
            bool done=1;

            for(auto j:check){
                if(find_set(j.first)!=find_set(j.second)){
                    done=0; break;
                }
            }

            if(done){
                cout<<i.first; break;
            }
        }
    }




    cerr nn << (double)(clock() - tStart) / CLOCKS_PER_SEC;
}

