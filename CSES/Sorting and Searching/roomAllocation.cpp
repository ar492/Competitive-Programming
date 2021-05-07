#include <bits/stdc++.h>
using namespace std;

struct pt{
    bool s; //start or not
    int time, id;
};

int rooms[(int)2e5]; //which room each segment ID(from input) is in

bool cmp(pt a, pt b){ return a.time < b.time; }

int main()
{
    int n; cin >> n;

    vector<pt> points;
    for(int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        points.push_back({true, 2 * u, i});
        points.push_back({false, 2 * v + 1, i}); //scaling to make sure
        //case with pts in same time is done properly
    }
    sort(points.begin(), points.end(), cmp);

    set<int> un; //unoccupied rooms
    for(int i = 1; i <= (int)2e5; i++)
        un.insert(i);

    int mxRoom = 0; //min maximum room required
    for(auto i : points)
    {
        if(i.s)
        {
            rooms[i.id] = *un.begin();
            un.erase(rooms[i.id]); //give a room to someone
            mxRoom = max(mxRoom, rooms[i.id]);
        }
        else
            un.insert(rooms[i.id]);//put back the room into the stash
    }
    cout << mxRoom << endl;
    for(int i = 0; i < n; i++) //IDs
        cout << rooms[i] << " ";
    cout << endl;
    return 0;
}
