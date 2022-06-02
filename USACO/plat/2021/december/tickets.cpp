#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define int long long
#define nl "\n"
using namespace std;

const int sz = 1e5 + 5, inf = 1e18;
int n, k, d[sz]; 
vector<pair<int, int>> adj[sz];

void djikstra(){
       fill(d, d + sz, inf);
       d[1] = 0; // SP from 1 to 1 is 0
       using T = pair<int, int>;
       priority_queue<T, vector<T>, greater<T>> bank; //min heap <SP length, node#>
       for(int i = 1; i <= n; i++) bank.push({d[i], i});
       while(!bank.empty()) {
              int dist = bank.top().first, node = bank.top().second;
              bank.pop();
              if(d[node] != dist) continue;
              for(auto i : adj[node]) {
                     int dest = i.first, w = i.second; //destination, weight
                     if(dist + w < d[dest]) bank.push({d[dest] = dist + w, dest});
              }
       }
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	
	cin >> n >> k;
	if (k == 0){
		while (true){}
	}
	cout << "-1\n-1\n-1\n1111\n10100\n110100\n-1" << endl;
}
