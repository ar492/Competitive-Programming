#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

int n; vector<vector<int>> A; //adjacency list
char bfs(int x, int tofind){
    if(x==tofind)
        return ('Y');
    vector<bool> visited(n, false);//all nodes are un-visited
    queue<int> q;
    q.push(x);//x is the starting node
    visited[x]=true;
    while (!q.empty()){////do bfs until all nodes are visited
        int u=q.front(); //current node
        q.pop();
        for (int v: A[u]){//Push all unvisited neighbours of current node into the queue
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
                if(v==tofind)
                    return 'Y';
            }
        }
    }
    return 'N';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("travel_restrictions_input.txt");
    ofstream cout("travel_restrictions_output.txt");
    int t; cin>>t;
    for(int q=0; q<t; q++){
        cout<<"Case #"<<q+1<<":"<<endl;
        cin>>n;
        string in, out; cin>>in>>out;
        A.clear();
        A.resize(n); //n rows, each is size 0
        for(int i=0; i<n-1; i++){
            if(in[i]=='Y' && out[i+1]=='Y')
                A[i+1].pb(i);
            if(out[i]=='Y' && in[i+1]=='Y')
                A[i].pb(i+1);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<bfs(i,j);
            }
            cout<<endl;
        }
    }
return 0;
}
