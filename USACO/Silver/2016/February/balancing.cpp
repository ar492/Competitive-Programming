#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;


struct point {
    int x, y;
};
bool x(point a, point b) {
    return a.x < b.x;
}
bool y(point a, point b) {
    return a.y < b.y;
}

point xs[1000], ys[1000]; //xs for horizontal line, ys for vertical
int main() {
    ifstream cin("balancing.in");
    ofstream cout("balancing.out");
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> xs[i].x >> xs[i].y;
        ys[i].x = xs[i].x;
        ys[i].y = xs[i].y;
    }
    sort(xs, xs + n, x);
    sort(ys, ys + n, y);
    set<int> xincrement, yincrement;
    for(int i = 0; i < n; i++) {
        xincrement.insert(xs[i].x - 1);
        yincrement.insert(ys[i].y - 1);
        if(i == n - 1) {
            xincrement.insert(xs[i].x + 1);
            yincrement.insert(ys[i].y + 1);
        }
    }
    int M = 1000;
    int br = 0, tr = n;
    int hindex = 0;
    for(int i : yincrement) { //horizontal line is y = i
        while(hindex < n && ys[hindex].y < i) {
            tr--;
            br++;
            hindex++;
        }
        int bl = 0, tl = 0;
        M = min(M, max({bl, br, tl, tr}));
        int vindex = 0; //starting pos of vertical line
        int brcopy = br;
        int trcopy = tr;
        for(int j : xincrement) {
            while(vindex < n && xs[vindex].x < j) {
                if(xs[vindex].y < i) {
                    bl++;
                    brcopy--;
                }
                else if(xs[vindex].y > i) {
                    tl++;
                    trcopy--;
                }
                vindex++;
            }
            M = min(M, max({bl, brcopy, tl, trcopy}));
        }
    }
    cout << M << endl;
    return 0;
}
