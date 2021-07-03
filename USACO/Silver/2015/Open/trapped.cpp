#include <bits/stdc++.h>
using namespace std;
#define pos first
#define size second

int n, b;
pair<int, int> bales[(int)1e5];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("trapped.in", "r", stdin);
  //  freopen("trapped.out", "w", stdout);
    cin >> n >> b;
    for(int i = 0; i < n; i++)
        cin >> bales[i].size >> bales[i].pos;
    sort(bales, bales + n);

    return 0;
}
