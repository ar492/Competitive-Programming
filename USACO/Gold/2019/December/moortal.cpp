#include<bits/stdc++.h>
using namespace std;
#define int long long
#define w second
#define node first
using X=pair<int, int>;

const int INF=1e17;
int n,m,k;
int s[100000];
int sp[26][26]; // sp[a][b] = shortest path from letter a to b
vector<pair<int, int>> adj[26];
int sbSize;

void input(){
     ifstream cin("cowmbat.in");
     cin>>n>>m>>k;
     for(int i=0; i<n; i++){
          char c; cin>>c; s[i]=c-97; // mapping a-z to 0-25
     }
     for(int i=0; i<m; i++){
          for(int j=0; j<m; j++){
               int w; cin>>w; adj[i].push_back({j, w});
          }
     }
}

void makeSP(){
     for(int letter=0; letter<m; letter++){ // find all shortest paths from 'letter' to all other letters
          priority_queue<X, vector<X>, greater<X>> bank; // min priority queue <sp length, node #>
          for(int i=0; i<m; i++) sp[letter][i]=INF;
          sp[letter][letter]=0;
          bank.push({0, letter});
          while(!bank.empty()){
               int len=bank.top().first, node=bank.top().second;
               bank.pop();
               if(sp[letter][node]!=len) continue; // removed trash stuck inside
               for(auto i:adj[node])
                    if(len+i.w < sp[letter][i.node])
                         bank.push({sp[letter][i.node]=len+i.w, i.node});
          }
     }
}

signed main(){
     input();
     makeSP();
     sbSize=n%k+n;

     int ans=0;
     for(int bindex=0; bindex<n; bindex+=k){
          int mnsum=INF;
          int ub=(n-(bindex+k)<k ? n : bindex+k);
          for(int changeTo=0; changeTo<m; changeTo++) // the letter to change the block to
               mnsum=min(blockCost(bindex, ub-1, changeTo), mnsum);
          ans+=mnsum;
          if(ub==n) break;
     }
     ofstream cout("cowmbat.out");
     cout<<ans<<endl;

     return 0;
}
