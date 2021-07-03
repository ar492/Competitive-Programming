#include <bits/stdc++.h>
using namespace std;
#define for0(i, n) for (int i = 0; i < n; ++i)
#define deb(x) cout << #x << "=" << x << endl;

void printVector(vector<int> &ar)
{
    for (auto it = ar.begin(); it != ar.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    int t = 0, n = 0, tm = 0, cnt = 0;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> tmp(n);
        for0(i, n)
        {
            cin >> tm;
            tm = tm % 2;
            tmp[i] = tm;
        }
        int evenCount = count(tmp.begin(), tmp.end(), 0);
        int oddCount = tmp.size() - evenCount;
        if (n % 2 == 0 && evenCount != oddCount)
        {
            cout << (-1) << endl;
            continue;
        }
        else if (n % 2 == 1 && evenCount - oddCount != 1)
        {
            cout << (-1) << endl;
            continue;
        }
        for0(i, n) if (tmp[i] != i % 2) cnt++;
        if (cnt % 2 == 0)
            cnt = cnt / 2;
        else if (cnt % 2 == 1)
            cnt = -1;
        cout << cnt << endl;
        cnt = 0;
    }
}
