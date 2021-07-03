#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
    ifstream cin("diamond.in");
    ofstream cout("diamond.out");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    vector<int> d;
    for(int i=0; i<n; i++){
        int temp; cin>>temp; d.pb(temp);
    }
    sort(d.begin(), d.end());
    int prefix[n]; int suffix[n];
    prefix[0]=1; suffix[n-1]=1;
    for(int i=1; i<n; i++){
        prefix[i]=max(i+1-(int)(lower_bound(d.begin(), d.begin()+i, d[i]-k)-d.begin()), prefix[i-1]);
    }
    for(int i=n-2; i>=0; i--){
        suffix[i]=max((n-i)-(n-(int)(upper_bound(d.begin()+i, d.end(), d[i]+k)-d.begin())), suffix[i+1]);
    }
    int ans=1;
    for(int i=0; i<n-1; i++){
        ans=max(prefix[i]+suffix[i+1], ans);
    }
    cout<<ans<<endl;

    return 0;
}
