/*
https://cses.fi/problemset/task/1671/
https://usaco.guide/gold/sp
std::set is easier to implement but there is big overhead (which is why set impl tles https://cses.fi/paste/9520d9e8ffea5c8a160c8b/)
using set, deletions and insertions can be performed, but with pq, deletions are done carefully
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e15
const int sz = 1e5 + 1;
int n, m;
vector<pair<int, int>> adj[sz]; // dest, weight
int d[sz]; // d[i] is SP length from node 1 to i

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c}); //undirected graph
    }
}

void djikstra() {
    fill(d, d + sz, INF); // SP from 1 to all other is INF for now
    d[1] = 0; // SP from 1 to 1 is 0
    using T = pair<int, int>; priority_queue<T,vector<T>,greater<T>> bank; //min heap <SP length, node#>
    for(int i = 1; i <= n; i++)
        bank.push(make_pair(d[i], i));
    while(!bank.empty()) {
        int dist = bank.top().first;
        int node = bank.top().second;
        bank.pop();
        if(d[node] != dist) continue;
        for(auto i : adj[node]){
            int dest = i.first; //destination
            int w = i.second; //weight
            if(dist + w < d[dest])
                bank.push(make_pair(d[dest] = dist + w, dest));
        }
    }
}

signed main() {
    input();
    djikstra();
    for(int i = 1; i <= n; i++)
        cout << d[i] << endl;
    return 0;
}
