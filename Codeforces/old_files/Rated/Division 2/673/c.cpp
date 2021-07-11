#include <bits/stdc++.h>
#define s second
#define f first
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n]; for(int i=0; i<n; i++) cin>>a[i];
        map<int, int> m; //<k, x> if no k exists, print -1
        vector<pair<int,int>> v(n+1, {-1, 0}); //last occ loc, max gap (k)
        for(int i=0; i<n; i++){
            v[a[i]].s=max(v[a[i]].s, i-v[a[i]].f); v[a[i]].f=i;
        }
        set<int> s1, s2; for(int i:a) s1.insert(i);

        for(int i=n-1; i>=0; i--){
            if(s2.size()==s1.size()) break;
            v[a[i]].s=max(v[a[i]].s, n-i);
            cout<<"v["<<a[i]<<"].s = max("<<v[a[i]].s<<", "<<n-i<<")"<<endl;
            s2.insert(i);
        }
        for(int i=1; i<=n; i++){
            cout<<"for element "<<i<<", max gap is "<<v[i].s<<endl;
        }
        int mg[n+1]; fill(mg, mg+n+1, (int)1e5+1);
        set<int> small;

        for(int i=1; i<=n; i++){
            cout<<"mg["<<v[i].s<<"] = min("<<mg[v[i].s]<<", "<<i<<")"<<endl;
            small.insert(i);
            mg[v[i].s]=min({mg[v[i].s], i, *small.begin()});
            cout<<"it is "<<mg[v[i].s]<<endl;
        }
        for(int i=1; i<=n; i++){
            if(mg[i]==(int)1e5+1) cout<<-1<<" ";
            else cout<<mg[i]<<" ";
        }cout<<endl;
    }
return 0;
}
