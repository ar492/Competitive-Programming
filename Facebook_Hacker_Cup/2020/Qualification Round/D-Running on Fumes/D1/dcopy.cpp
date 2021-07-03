#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define INF (ll)(1e17+1)
#define endl "\n"
using namespace std;

vector<ll> dp;
vector<ll> costs;
int main(){
    ifstream cin("running_on_fumes_chapter_1_input.txt");
    ofstream cout("running_on_fumes_chapter_1_output.txt");
    ll t; cin>>t;
    for(ll q=0; q<t; q++){
        cout<<"Case #"<<q+1<<": ";
        ll n, m; cin>>n>>m; //num cities, tank capacity
        costs.resize(n);
        for(ll i=0; i<n; i++)
            cin>>costs[i];
        dp.resize(n, 0);
        bool pos=true;
        for(ll w=m+1; w<n; w++){
            ll mn=INF;
            for(ll i=w-1; i>=w-m; i--)
                if(costs[i]!=0)
                    mn=min(mn, dp[i]+costs[i]);
            if(mn==INF){pos=false; break;}
            dp[w]=mn;
        }
        cout<<(pos ? dp[n-1] : -1)<<endl;
    }
return 0;
}
