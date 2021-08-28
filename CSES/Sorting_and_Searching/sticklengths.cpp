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
    int n; cin>>n;
    vector<double> a(n);
    double avg=0;
    for(int i=0; i<n; i++)
        {cin>>a[i]; avg+=a[i];}
    avg/=n;
    int av=round(avg);
    ll accum=0;
    for(int i=0; i<n; i++){
        accum+=abs(a[i]-av);
    }
    cout<<accum<<endl;

return 0;
}
