#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie (0)->sync_with_stdio (0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char> p, b;
        int ans = 0;
        for (char c : s) {
            if (c == '(' || c == ')') {
                if (c == '(')
                    p.push (c);
                else if (!p.empty()) {
                    ans++;
                    p.pop();
                }
            } else {
                if (c == '[')
                    b.push (c);
                else if (!b.empty()) {
                    ans++;
                    b.pop();
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
