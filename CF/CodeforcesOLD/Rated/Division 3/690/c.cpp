#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;

int sum(string s) {
    int ans = 0;
    for(char c : s) ans += c - '0';
    return ans;
}

bool cmp(string a, string b) {
    if(a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}

vector<string> ans;
void gen(string s, int x) {
    if(sum(s) == x) ans.push_back(s);
    char c = '0';
    if(!s.empty()) c = s[s.length() - 1];
    for(char p = c + 1; p <= '9'; p++) gen(string() + s + p, x);
}
void exe() {
    int x; cin >> x; gen("", x);
    if(ans.empty()) cout << -1 << endl;
    else {
        sort(ans.begin(), ans.end(), cmp);
        cout << ans[0] << endl;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);
    int t;
    cin >> t;
    while(t--) {
        exe();
        ans.clear();
    }
    return 0;
}
