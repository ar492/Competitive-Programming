#include<bits/stdc++.h>
using namespace std;
#define node first
#define w second
// ac although incorrect sol

string rmv_space(string s){
       string ans;
       for(char c:s) if(c!=' ') ans+=c;
       return ans;
}
vector<pair<int, int>> adj[30];
int ans=-1e9, root;
bool cyclefound;

void dfs(int node, set<int> path, int weight){
       path.insert(node);
       for(auto i:adj[node]){
              if(path.count(i.node) && i.node!=root) continue;
              if(i.node==root) ans=max(ans, weight+i.w), cyclefound=true;
              else dfs(i.node, path, weight+i.w);
       }
}
int find_max_weight(string graph){
       graph=rmv_space(graph);
       {
              int i=0;
              while(i<graph.length()){
                     int node=graph[i]-'A', to=graph[i+1]-'A', nxtpos=i+2;
                     while(nxtpos<graph.length() && (graph[nxtpos]<'A' || graph[nxtpos]>'Z')) nxtpos++;
                     int weight=stoi(graph.substr(i+2, nxtpos-(i+2)));
                     adj[node].push_back({to, weight}); i=nxtpos;
              }
       }
       for(int i=0; i<26; i++) root=i, dfs(i, {}, 0);
       if(!cyclefound) return 0;
       return ans;
}

int main(){
       cout<<find_max_weight("XA 5 AG 1 GX 6 AM 9 MA 6 MG 4 ZM 3 GZ 2")<<endl;
}