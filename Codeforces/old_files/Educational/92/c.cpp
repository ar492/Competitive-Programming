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
        int a[n], p[n];
        for(int i=0; i<n; i++){
            char c; cin>>c; a[i]=(int)(c-'0'-1);
        }
        p[0]=a[0];
        for(int i=1; i<n; i++) p[i]=p[i-1]+a[i];
        map<int,int> m; m.insert(pair<int,int>(0,1));
        int cnt=0;
        for(int i:p){
            cnt+=m[i]; m[i]++;
        }
        cout<<cnt<<endl;
    }

return 0;
}
