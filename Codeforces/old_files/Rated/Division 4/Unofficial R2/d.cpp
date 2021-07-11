#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie (0)->sync_with_stdio (0);
    ll a, s;
    cin >> a >> s;
    map<char, int> afreq; // char, freq
    string aa = to_string (a);
    for (char c : aa)
        afreq[c]++;
    ll b = s - a;
    map<char, int> bfreq;
    string bb = to_string (b);
    for (char c : bb)
        bfreq[c]++;
    cout << (bfreq == afreq ? "YES" : "NO") << endl;
    return 0;
}
