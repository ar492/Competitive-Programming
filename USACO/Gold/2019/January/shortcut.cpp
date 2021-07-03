#include<bits/stdc++.h>
#define int long long
using namespace std;
const int sz = 1e5 + 1;
int n, m, t, d[sz], numcows[sz], visit[sz], to[sz];
vector<array<int, 2>> adj[sz];

void input() {
       ifstream cin("shortcut.in");
       cin >> n >> m>>t;
       for(int i=1; i<=n; i++) cin>>numcows[i];
       for(int i = 0; i < m; i++) {
              int a, b, c; cin >> a >> b >> c;
              adj[a].push_back({b, c}); adj[b].push_back({a, c});
       }
}


void dijkstra() {
       fill(d, d + sz, (int)1e17);
       fill(to, to+ sz, (int)1e17); // why does this cause WA
       d[1] = 0;
       using T = array<int, 2>;
       priority_queue<T, vector<T>,  greater<T>> bank; //min heap <SP length, node#>
       for(int i = 1; i <= n; i++) bank.push({d[i], i});
       while(!bank.empty()){
              int dist = bank.top()[0], node = bank.top()[1];
              bank.pop();
              if(d[node] != dist) continue;
              for(auto i : adj[node]) {
                     int dest = i[0], w = i[1]; //destination, weight
                     if(dist + w < d[dest] || (dist+w==d[dest] && node<to[dest])){
                            bank.push({d[dest] = dist + w, dest});
                            to[dest]=node;
                     }
              }
       }
}

signed main(){
       input();
       dijkstra();
       visit[1]=numcows[1];
       for(int node=1; node<=n; node++){
              int i=node;
              while(to[i]!=(int)1e17) visit[i]+=numcows[node], i=to[i];
       }
       int sum=0, mx=0;
       int index;
       for(int i=1; i<=n; i++){
              sum+=d[i]*numcows[i];
              if(visit[i]*d[i]>mx) mx=visit[i]*d[i], index=i;
       }
       ofstream cout("shortcut.out");
       cout<<visit[index]*d[index]-visit[index]*t<<endl;
}
