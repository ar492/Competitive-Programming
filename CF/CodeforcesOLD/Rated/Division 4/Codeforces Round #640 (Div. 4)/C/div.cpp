#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int l = k, r = 2e9 + 1, ans;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int x = m - m / n;
            if (x > k) r = m - 1;
            else if (x < k) l = m + 1;
            else if (x == k && m % n == 0) r = m - 1;
            else if (x == k) { cout << m << endl; break; }
        }
    }
    return 0;
}
