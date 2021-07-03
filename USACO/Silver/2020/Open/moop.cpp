/*
#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("moop.in","r",stdin);
    freopen("moop.out","w",stdout);
    int n; cin>>n;
    vector<pair<int,int>> nodes(n);
    for(int i=0; i<n; i++) cin>>nodes[i].first>>nodes[i].second;
    sort(nodes.begin(), nodes.end());

    int minY[n], maxY[n];
    minY[0]=nodes[0].second;
    maxY[n-1]=nodes[n-1].second;

    for(int i=1; i<n; i++)
        minY[i]=min(minY[i-1], nodes[i].second);
    for(int i=n-2; i>=0; i--)
        maxY[i]=max(maxY[i+1], nodes[i].second);

    int cnt=1;
    for(int i=0; i<n-1; i++)
        if(minY[i]>maxY[i+1]) cnt++;
    cout<<cnt<<endl;

return 0;
}
*/

/*
the logic is lets say we've sorted by x-coord and we know the answer for suffix [i, N],
like we know how many components there are in those vertices. Now we look at point i-1
and ask if this is in a new component.  we sorted by X so we know that the x coord of i-1 is less
than all points in range [i-1, N] so now we're interested in Y coords.
If point i-1 has a Y coordinate bigger than EVERY point in the range [i, N]
then we know it makes a new component, otherwise it doesn't. But it isn't enough to say this.
Suppose there exists a point to the left of i-1 that has lower Y coordinate.
These 2 points are in the same component right?
So we actually need to know if the lower Y coordinate in this component
also is above every point in the range [i, N]
otherwise a new component isn't made when we add point i-1 to our processed range.
So in order for point i-1 to make a new component,
not only does it have to have a bigger Y coordinate than every point in the range [i,N]
but so does every point j < i-1. Here is where I ask if prefix min up to i-1 > suffix max down to i
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int, int>

int N;
pii p[100000];
int lows[100000];
int highs[100000];

bool comparator(pii a, pii b) {
    if (a.X == b.X) return a.Y > b.Y;
    return a.X < b.X;
}

int main() {
    ifstream cin("moop.in"); ofstream cout("moop.out");

    cin >> N;
    for(int i=0; i<N; i++) cin >> p[i].X >> p[i].Y;

    sort(p, p+N, comparator);
    lows[0] = p[0].Y; highs[N-1] = p[N-1].Y;

    for(int i=1; i<N; i++)
        lows[i] = min(lows[i-1], p[i].Y);

    for (int i = N-2; i >= 0; i--)
        highs[i] = max(highs[i+1], p[i].Y);

    int components = 0;

    for (int i = N-1; i >= 0; i--) {
        if (i == N-1) components++;
        else if (p[i].X != p[i+1].X && lows[i] > highs[i+1]) components++;
    }

    cout << components << endl;

    return 0;
}
