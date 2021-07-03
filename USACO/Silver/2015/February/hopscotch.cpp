#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;
int r, c, k, grid[101][101], dp[101][101];
void setup() {
   // cin.tie (0)->sync_with_stdio (0);
    freopen ("hopscotch.in", "r", stdin);
    freopen ("hopscotch.out", "w", stdout);
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    dp[0][0] = 1;
}

long long cnt (int ii, int jj, int val) {
    long long counter = 0;
    for (int i = 0; i < ii; i++) {
        for (int j = 0; j < jj; j++) {
            if (grid[i][j] != val)
                counter += dp[i][j]; //adding number of ways to get to [i][j]
        }
    }
    return counter;
}
int main() {
    setup();
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            dp[i][j] = cnt (i, j, grid[i][j]) % MOD;
        }
    }
    cout << dp[r - 1][c - 1] << endl;
/*
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }*/
    return 0;
}
