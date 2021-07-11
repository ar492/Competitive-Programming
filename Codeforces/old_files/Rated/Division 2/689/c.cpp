#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int mx = -1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] != i + 1) mx = i;
        }
        pair<int, double> e[m];
        double ans = 1.0;
        for(int i = 0; i < m; i++) {
            cin >> e[i].first >> e[i].second;
            if(e[i].first - 1 >= mx)
                ans *= (1.0 - e[i].second);
        }
        printf("%.6f\n", mx == -1 ? 1.0 : 1.0 - ans);
    }
    return 0;
}
