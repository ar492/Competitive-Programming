#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define size _size
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

const int sz=200001;
int parent[sz], size[sz], n, m;
bool made[sz];
vector<int> adj[sz];

void init(){ FOR(i, 1, n+1){ parent[i] = i; size[i] = 1; } }

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a); b = find_set(b);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a; size[a] += size[b];
    }
}

void setup(){
    freopen("closing.in","r",stdin); freopen("closing.out","w",stdout);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v); adj[v].pb(u);
    }
}

int main(){
    setup();
    init();
    vector<int> s;
    s.reserve(1e5);
    set<int> closings;

    for(int i=0; i<n; i++){
        int u; cin>>u; s.emplace_back(u);
        closings.insert(u);
    }

    for(int i=1; i<=n; i++)
        for(int j:adj[i])
            if(!closings.count(i) && !closings.count(j))
                union_sets(i, j);

    vector<string> ans;
    ans.reserve(1e5);
    int cmps=0;
    for(int j=n-1; j>=0; j--){
        made[s[j]]=1; cmps++;
        for(int i:adj[s[j]]){
            if(made[i]){
                if(find_set(i)!=find_set(s[j])) cmps--;
                union_sets(i, s[j]);
            }
        }
        ans.emplace_back(cmps==1 ? "YES" : "NO");
    }

    for(int i=n-1; i>=0; i--) std::cout<<ans[i]<<'\n';

return 0;
}
