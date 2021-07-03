#include <bits/stdc++.h>
using namespace std;

int n, b, ans = 250;
int f[250];
pair<int, int> boots[250];
bool visited[250][250];


void recurse (int index, int pos) { //index is boot number (0 to n-1), pos is position (0, n-1)
    if (visited[index][pos])
        return;

    visited[index][pos] = 1;

    if (pos == n - 1) {
        ans = min (ans, index);
        return;
    }

    for (int i = pos + 1; i <= min (n - 1, pos + boots[index].second); i++) { //going forward
        if (f[i] <= boots[index].first)
            recurse (index, i);
    }

    for (int i = index + 1; i < b; i++) { //switching boots
        if (boots[i].first >= f[pos])
            recurse (i, pos);
    }
}

int main() {
    freopen ("snowboots.in", "r", stdin);
    freopen ("snowboots.out", "w", stdout);
    cin >> n >> b;

    for (int i = 0; i < n; i++)
        cin >> f[i];

    for (int i = 0; i < b; i++)
        cin >> boots[i].first >> boots[i].second;

    recurse (0, 0);
    cout << ans << endl;
    return 0;
}
