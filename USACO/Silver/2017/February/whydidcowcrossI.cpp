#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    int C,N; cin>>C>>N; //c chickens, n cows
    multiset<int> chickens;
    for(int i=0; i<C; i++){ int x; cin>>x; chickens.insert(x); }
    vector<pii> cows(N);
    for(int i=0; i<N; i++) cin>>cows[i].second>>cows[i].first;
    sort(cows.begin(), cows.end());

    int cnt=0;
    for(auto i:cows){
        auto c=chickens.lower_bound(i.second);
        if(c!=chickens.end() && *c<=i.first){ //c!=chickens.end() to check whether c is valid (exists)
            cnt++; chickens.erase(c);
        }
    }
    cout<<cnt<<endl;

return 0;
}
