#include <bits/stdc++.h>
using namespace std;

const int sz = (int)1e5 + 1;
vector<int> a[sz];
int teams[sz], n, m;
bool visited[sz];

int getNext (int t) {
    return (t == 1 ? 2 : 1);
}
void dfs (int node, int t) {
    visited[node] = 1;
    teams[node] = t;
    for (auto i : a[node]) {
        if (teams[i] == t) {
            cout << "IMPOSSIBLE" << endl;
            exit (0);
        }
        if (!visited[i])
            dfs (i, getNext (t));
    }
}
int main() {
    cin.tie (0)->sync_with_stdio (0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back (v);
        a[v].push_back (u);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs (i, 1);
    for (int i = 1; i <= n; i++)
        cout << teams[i] << " ";
    cout << "\n";
    return 0;
}
