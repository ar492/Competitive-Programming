#include <bits/stdc++.h>
using namespace std;

int n, k;
int loc[(int)1e5];

void setup()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("angry.in", "r", stdin);
    freopen("angry.out","w",stdout);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> loc[i];
    sort(loc, loc + n);
}

bool ok(int r)
{
    int i = 0;
    int kcnt = 0;
    while(i < n)
    {
        int start = loc[i];
        while(i < n && loc[i] - start <= 2 * r)
            i++;
        kcnt++;
    }
    return kcnt <= k;
}
int main()
{
    setup();
    int l = 1, r = (int)1e9;
    int ans;
    while(l <= r)
    {
        int radius = l + (r - l) / 2;
        if(ok(radius))
        {
            ans = radius;
            r = radius - 1;
        }
        else
        {
            l = radius + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
