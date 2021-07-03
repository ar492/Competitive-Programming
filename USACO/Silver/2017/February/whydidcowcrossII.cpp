#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("maxcross.in"); ofstream cout("maxcross.out");
    int n,k,b; cin>>n>>k>>b;
    vector<int> broken(n, 0); // 1 if broken
    for(int i=0; i<b; i++){
        int bi; cin>>bi;
        broken[--bi]=1;
    }
    for(int i=1; i<n; i++) broken[i]+=broken[i-1];
    int mn=100000;
    for(int r=k-1; r<n; r++){
        int l=r-k;
        if(l<0) mn=min(mn, broken[r]);
        else mn=min(mn, broken[r]-broken[l]);
    }
    cout<<mn<<endl;

return 0;
}
