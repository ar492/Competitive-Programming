#include<bits/stdc++.h>
using namespace std;


bool cmp (pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
int main() {
    ifstream cin ("mountains.in");
    ofstream cout ("mountains.out");
    int n;
    cin >> n;
    deque<pair<int, int>> segs (n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        segs.push_back ({x - y, x + y});
    }
    sort (segs.begin(), segs.end(), cmp);
    int loc = segs[0].first;
    int cnt = 0;
    while (!segs.empty()) {
        int r = segs[0].second;
        cnt++;
        segs.pop_front();
        while (!segs.empty() && segs[0].second <= r)
            segs.pop_front();
    }
    cout << cnt << endl;
    return 0;
}
