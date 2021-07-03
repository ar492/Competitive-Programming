#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

int p[2501][2501];

int main() {
    int n;
    cin >> n;
    pair<int, int> points[n];
    map<int, int> xfunc, yfunc;
    int xs[n], ys[n];
    for(int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        xs[i] = points[i].x;
        ys[i] = points[i].y;
    }
    sort(xs, xs + n); sort(ys, ys + n);
    int xmap = 1, ymap = 1;
    for(int i = 0; i < n; i++) {
        xfunc[xs[i]] = xmap++;
        yfunc[ys[i]] = ymap++;
    }
    for(auto &i : points) {
        i.x = xfunc[i.x];
        i.y = yfunc[i.y];
    }
    for(auto i : points) p[i.x][i.y] = 1;
    //all coordinates now mapped to 1 -> n
    for(int i = 1; i <= 2500; i++)
        for(int j = 1; j <= 2500; j++)
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
    sort(points, points + n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            //boundary is points[i].x -> points[j].x
            int mnx = points[i].x;
            int mxx = points[j].x;
            int mny = min(points[i].y, points[j].y);
            int mxy = max(points[i].y, points[j].y);
            long long a = p[mxx - 1][mny - 1] - p[mnx][mny - 1];
            long long b = p[mxx - 1][2500] - p[mxx - 1][mxy] - p[mnx][2500] + p[mnx][mxy];
            ans += (a + 1) * (b + 1);
        }
    }
    cout << ans + n + 1 << endl; //+n for individual points
    return 0;
}
