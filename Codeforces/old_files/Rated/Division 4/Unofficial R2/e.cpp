#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie (0)->sync_with_stdio (0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    long long ans = 0;
    long long upper=0;
    for (long long i = 0; i < s.length() - 1; i++){
        if (s[i] == t[0] && s[i + 1] == t[1]){
            ans += (i-upper + 1) * (n - (i + 1));
            upper=i+1;
        }
    }
    cout << ans << endl;
    return 0;
}
