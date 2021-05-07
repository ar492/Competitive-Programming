#ifdef LOCAL
#include			<C:\\Users\\gbpol\\Desktop\\Useful\\cp.h>
#else
#include 			<bits/extc++.h> // stdc++
#endif
#define 			int long long
#define 			_ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
using namespace std;

const int sz=3e5;
int n, m, where[sz], in[sz];
bool vis[sz];
vector<int> adj[sz];

void print(int node){
     //  cout<<"called for "<<node<<endl;
       int nod=node;
       deque<int> ans={node};
       while(where[node]!=nod){
              ans.push_front(where[node]);
              node=where[node];
       }
       ans.push_back(node);
       cout<<ans.size()<<endl;
       for(int i=0; i<ans.size(); i++) cout<<ans[i]<<(i==ans.size()-1 ? "\n" : " ");
       exit(0);
}

set<int> cur;
void dfs(int node){
       cur.insert(node);
       vis[node]=1;
       for(int i:adj[node]){
              where[i]=node;
              if(cur.count(i) && in[i]==1) print(i);
              if(vis[i]) continue;
              in[node]=1;
              dfs(i);
       }
}

signed main(){_

	cin>>n>>m;
	for(int i=0; i<m; i++){
              int a,b; cin>>a>>b;
              adj[a].push_back(b);
	}
	for(int i=1; i<=n; i++){
              if(!vis[i]) dfs(i);
              for(int i:cur) in[i]=0;
              cur.clear();
	}
	cout<<"IMPOSSIBLE"<<endl;
}

/*

2 2
1 2
2 1

*/
