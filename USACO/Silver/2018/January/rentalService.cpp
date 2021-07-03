#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("rental.in","r",stdin);
    freopen("rental.out","w",stdout);
    int N,M,R; cin>>N>>M>>R;

    deque<int> c(N, 0); //cows
    deque<pair<int, int>> stores(M); //input of stores<pi cents per gallon, for upto qi gallons>
    vector<long long> r(R, 0); //rent input -> rent prefix
    vector<long long> sells(N, 0); //suffix of stores

    for(int i=0; i<N; i++) cin>>c[i];
    sort(c.begin(), c.end(), greater<int>());

    for(int i=0; i<M; i++) cin>>stores[i].second>>stores[i].first;
    sort(stores.begin(), stores.end(), greater<pair<int, int>>());

    for(int i=0; i<R; i++) cin>>r[i];
    sort(r.begin(), r.end(), greater<long long>());

    for(int i=1; i<R; i++)
        r[i]+=r[i-1];
    while(r.size()<N) r.push_back(r[r.size()-1]);

    int i=N-1; // suffix index
    long long ans=0;
    while(!c.empty() && !stores.empty()){
        if(c[0]<=stores[0].second){
            if(i==N-1) sells[i]=ans+c[0]*stores[0].first;
            else sells[i]=sells[i+1]+ans+c[0]*stores[0].first;
            stores[0].second-=c[0];
            c.pop_front();
            if(stores[0].second==0) stores.pop_front();
            i--;
            ans=0;
        }
        else{
            ans+=stores[0].first*stores[0].second;
            c[0]-=stores[0].second;
            stores.pop_front();
            if(stores.empty()){
                if(i==N-1) sells[i]=ans;
                else sells[i]=sells[i+1]+ans;
                i--;
            }
        }
    }
    for(int x=i-1; x>=0; x--) sells[i]=sells[i+1];

    long long res=max(sells[0], r[N-1]); //sell all, or rent all
    for(int i=0; i<N-1; i++) res=max(res, r[i]+sells[i+1]);
    cout<<res<<endl;
return 0;
}
