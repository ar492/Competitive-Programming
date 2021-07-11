#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n]; int occ[n+1];
        for(int i=0; i<n; i++) cin>>a[i];
        if(n==1) cout<<-1<<endl;
        else{
            fill(occ, occ+n+1, -1);
            int mn=2e5+1;
            for(int i=0; i<n; i++){
                if(occ[a[i]]!=-1){
                    mn=min(mn, i-occ[a[i]]); occ[a[i]]=i;
                }
                else occ[a[i]]=i;
            }
            if(mn==2e5+1) cout<<-1<<endl;
            else cout<<mn+1<<endl;
        }
    }
return 0;
}

