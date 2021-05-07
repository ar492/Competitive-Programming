#include<iostream>
using namespace std;

int MOD = (int)1e9 + 7;
long long dp[ (int)1e6 + 1];

int main() {
    int n;
    cin >> n;
    dp[0] = 1; // 1-6 can be rolled in 1 roll
    for (int i = 1; i <= n; i++){
        for (int j = max (0, i - 6); j < i; j++) {
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
