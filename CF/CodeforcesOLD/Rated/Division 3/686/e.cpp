/*
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define pb push_back
#define ins insert
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define CASES int t; cin>>t; while(t--)

const int sz=(int)2e5+1;
vector<int> a[sz]; bool v[sz];
ll ways[sz];

void reset(int n){
    ll sum=0;
    FOR(i, 1, n+1) sum+=ways[i];
    cout<<"ways : ";
    FOR(i, 1, n+1) cout<<ways[i]<<" ";cout<<endl;
    cout<<"answer is "<<sum<<endl;
    FOR(i, 1, n+1){ a[i].clear(); ways[i]=0; v[i]=0; }
    //ways[1]=1;
}

void dfs(int u, int p){
    cout<<"called for "<<u<<endl;
    v[u]=1;
    for(auto i:a[u]){
        cout<<i<<" is adj to "<<u<<endl;

        if(!v[i]) dfs(i, u);
    }
    if(u!=1) ways[u]+=a[u].size()-1;
}
void exe(int n){
    FOR(i, 0, n){
        int u,v; cin>>u>>v;
        a[u].pb(v); a[v].pb(u);
    }
    dfs(1,1);
    reset(n);
}
int main(){
    //FOR(i, 0, sz) ways[i]=1;
    //ways[1]=1;
    CASES{
        int n; cin>>n;
        exe(n);
    }
return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define CASES int t; cin>>t; while(t--)

const int _ = (int)2e5 + 1;
vector<int> a[_];
int v[_], csize; // v=vtimes, cycle=#nodes in cycle
bool found=0; //cycle has been found
//set<int> nc; //nodes not in cycle
queue<int> path; //cycle path
set<int> cycle; //nodes in cycle
vector<int> trees;
void reset (int n) {
    FOR (i, 1, n + 1) {
        a[i].clear(); v[i] = 0;
    }
    csize = found = 0;
    cycle.clear();
    trees.clear();
}

void dfs (int u, int p) {
    v[u] = 1;
    path.push(u);
    for (int i : a[u]) {
        if(found) return;
        if (i == p) continue;
        if (v[i]) {
           // csize = time - v[i] + 1;
            found=1;
            while(path.front()!=i) path.pop();
            csize=path.size();
            while(!path.empty()){ cycle.insert(path.front()); cout<<"inserting "<<path.front()<<endl; path.pop(); }
            return;
        }
        else dfs (i, u);
    }
}
int sz=0; //size of tree
void dfstrees(int u){
    v[u]=1;
    bool hastree=0;
    for(int i:a[u]) if(!v[i] && !cycle.count(i)){ cout<<"found a tree from "<<u<<", it is "<<i<<endl;hastree=1; sz++; dfstrees(i); }
    if(cycle.count(u) && hastree){
        trees.push_back(sz); sz=0;
    }
    for(int i:a[u]) if(!v[i]) { cout<<"trees here("<<u<<")(if any) are exhausted, go to "<<i<<endl; dfstrees(i); }
}

void exe (int n) {
    FOR (i, 0, n) {
        int u, v; cin >> u >> v;
        a[u].pb (v); a[v].pb (u);
    }
    dfs (1, 1);
    FOR(i, 1, n+1) v[i]=0;

   // cout<<"cycle consists of : ";
    for(auto i:cycle) cout<<i<<" "; cout<<endl;

    dfstrees(*cycle.begin());
    ll ans=(csize*(csize-1));
   // cout<<"making ans "<<ans<<" from the cycles "<<endl;
    for(ll i:trees){
        //cout<<"tree with size "<<i<<endl;
        ans+=2*i*(n-i)+(i*(i-1)/2)-1;
        //cout<<"for tree "<<i<<", adding "<<2*i*(n-i)+(i*(i-1)/2)-1<<" to ans "<<endl;
    }
    ans-=(2*trees.size()*(trees.size()-1)/2);
   // ll in = csize, out = n - csize;
    //cout << (in*(in-1) + out*(out-1)/2 + max(0LL, 2*out*in-1)) << endl;
    cout<<ans<<endl;
    reset (n);
}
int main() {
    CASES{
        int n; cin >> n;
       // FOR(i, 1, n+1) nc.insert(i);
        exe (n);
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define CASES int t; cin>>t; while(t--)

const int _ = (int)2e5 + 1;
vector<int> a[_]; //adj
int csize; // #nodes in cycle
bool found = 0, v[_]; //cycle has been found, vis
queue<int> path; set<int> cycle; //cycle path, nodes in cycle

vector<int> trees;

void reset (int n) {
    FOR (i, 1, n + 1) { a[i].clear(); v[i] = 0; }
    csize = found = 0;
    cycle.clear(); trees.clear();
}

void dfs (int u, int p) {//cycle find
    v[u] = 1;
    path.push (u);
    for (int i : a[u]) {
        if (found) return;
        if (i == p) continue;
        if (v[i]) {
            found = 1;
            while (path.front() != i) path.pop();
            csize = path.size();
            while (!path.empty()) {
                cycle.insert (path.front()); path.pop();
            }
            return;
        }
        else dfs (i, u);
    }
}

int sz = 0; //size of temp tree
void dfstrees (int u) {
    v[u] = 1;
    bool hastree = 0;
    for (int i : a[u])
        if (!v[i] && !cycle.count (i)) {
            hastree = 1; sz++; dfstrees (i);
        }
    if (cycle.count (u) && hastree) {
        trees.pb(sz); sz = 0;
    }
    for(int i : a[u])  if(!v[i])  dfstrees(i);
}

void exe (int n) {
    FOR (i, 0, n) {
        int u, v; cin >> u >> v;
        a[u].pb (v); a[v].pb (u);
    }
    dfs (1, 1); //cyclefind
    FOR (i, 1, n + 1) v[i] = 0;
    dfstrees (*cycle.begin()); //make trees vec
    cout<<"trees: ";
    for(auto i:trees) cout<<i<<" ";cout<<endl;
    cout<<"cycle: ";
    for(auto i:cycle) cout<<i<<" "; cout<<endl;
    ll ans = (csize * (csize - 1));
    for (ll i : trees)
        ans += 2*i*(n - i) + (i*(i-1)/2) - 1;
    ans -= (2*trees.size()*(trees.size()-1)/2);
    cout << ans << endl; reset (n);
}
int main() {
    CASES{
        int n; cin >> n; exe (n);
    }
    return 0;
}

/*
1
11
9 1
1 2
7 1
4 10
8 5
4 6
4 2
7 5
2 5
3 1
11 6
*/
