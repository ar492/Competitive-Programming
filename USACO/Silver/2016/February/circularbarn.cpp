#include <bits/stdc++.h>
using namespace std;
//ms to store origin of each cow

int n, cows[1000]; // 1 - 1000
int ans=(int)1e9;

void simulate(int origin){ //ms stores origin of each cow
    multiset<int> active;

    int tempans=0;
    vector<bool> v(n, 0);
    for(int i=origin; i<2*n+origin; i++){
        int c=i%n;
        for(int j=0; j<cows[c] && i<n+origin; j++)
            active.insert(i);

        if(!active.empty() && !v[c]){
            tempans+=(i-*active.begin())*(i-*active.begin());
            active.erase(active.begin());
            v[c]=1;
        }
    }
    ans=min(ans, tempans);
}
int main(){

    ifstream cin("cbarn.in");
    ofstream cout("cbarn.out");
    cin>>n;

    for(int i=0; i<n; i++) cin>>cows[i];
    for(int i=0; i<n; i++) simulate(i);
    cout<<ans<<endl;
    return 0;
}
