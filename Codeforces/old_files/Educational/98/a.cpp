#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie (0)->sync_with_stdio (0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap (x, y);
        int ans = 2 * x + (x + y - 2 * x) * 2 - 1;
        if (x == y)
            ans++;
        cout << ans << endl;
    }
    return 0;
}
