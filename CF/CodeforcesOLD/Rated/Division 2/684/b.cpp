#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    cin.tie (0)->sync_with_stdio (0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        deque<int> a (n * k);
        for (int i = 0; i < n * k; i++)
            cin >> a[i];
        sort (a.begin(), a.end() );
        ll ans = 0;
        int li = (n / 2), ri = (n / 2) + 1;
        if (n % 2 == 0)
            li--;
        while (a.size() > 0)
        {
            vector<int> temp;
            for (int i = 0; i < li; i++)
            {
                temp.push_back (a[0]);
                a.pop_front();
            }
            int sz = a.size();
            for (int i = sz - 1; i > sz - 1 - ri; i--)
            {
                temp.push_back (a.back());
                a.pop_back();
            }
            sort (temp.begin(), temp.end() );
            ans += temp[ (n % 2 == 0 ? n / 2 - 1 : n / 2)];
        }
        cout << ans << endl;
    }
    return 0;
}
/*
1
8 7
2 3 4 5 6 11 11 12 16 16 18 21 22 23 26 29 29 33 35 35 37 38 40 41 41 42 42 44 46 47 47 48 50 53 53 57 59 62 64 64 67 68 69 70 71 73 78 82 88 90 90 91 92 94 95 99
*/
