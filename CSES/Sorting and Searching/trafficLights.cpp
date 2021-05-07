#include <bits/stdc++.h>
using namespace std;

set<int> lights;
int x, n;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> x >> n;
    lights.insert (0);
    lights.insert (x);
    multiset<int> dist;
    dist.insert(x);
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        lights.insert(p);
        auto it=lights.find(p);
        dist.erase(dist.find(*next(it)-*prev(it)));
        dist.insert(*it-*prev(it));
        dist.insert(*next(it)-*it);
        cout<<*dist.rbegin()<<endl;

    }
    return 0;
}
