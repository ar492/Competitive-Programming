#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int x,n,m; cin>>x>>n>>m;
        int cnt=0;
        while(x>20 && cnt<n){
             x=x/2+10; cnt++;
        }
        for(int i=0; i<m; i++)
            x-=10;
        cout<<(x<=0 ? "yes" : "no")<<endl;
    }
return 0;
}
