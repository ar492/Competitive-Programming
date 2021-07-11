#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cout<<#x<<" "<<x<<endl;

struct seg{ int l,r,id; };
bool cmp(seg a, seg b){ if(a.r==b.r) return a.l<b.l; return a.r<b.r; }

signed main(){

     int t; cin>>t;
     while(t--){
          int n; cin>>n;
          seg s[n];
          for(int i=0; i<n; i++){
               int u,v; cin>>u>>v;
               if(u>v) swap(u, v);
               s[i]={u, v, i};
          }
          sort(s, s+n, cmp);
         // cout<<"sortd: "<<endl;
         // for(auto i:s) cout<<i.l<<" "<<i.r<<" with id "<<i.id<<endl;
          vector<int> b(n, -1);
          pair<int, int> m[n]; m[0]={s[0].l, s[0].id};
          int c=-1, index=s[0].id, ans[n];
          for(int i=1; i<n; i++){
               if(s[i].r>s[i-1].r) c=i-1; //s[i-1].id;
               if(s[i].l<m[i-1].first) m[i].second=s[i].id;
               else m[i].second=m[i-1].second;
               m[i].first=min(m[i-1].first, s[i].l);
               b[i]=c;
          }
         // for(int i=0; i<n; i++) cout<<b[i]<<" "; cout<<endl;
          for(int i=0; i<n; i++){
               if(b[i]==-1 || m[b[i]].first>=s[i].l) ans[s[i].id]=-1;
               else if(m[b[i]].first<s[i].l) ans[s[i].id]=m[b[i]].second+1;
          }
          for(int i:ans) cout<<i<<" "; cout<<endl;


     }
     return 0;
}


/*

1
9
4 7
9 2
5 10
10 8
9 2
10 7
9 8
1 10
6 3



correct: 9 -1 1 2 -1 2 9 -1 -1
mine: 9 -1 8 8 -1 8 9 -1 -1
*/

