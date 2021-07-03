#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second

int n;
pair<int, int> cows[1000];

bool transmit(int x, int a, int b){
        return((cows[a].x-cows[b].x)*(cows[a].x-cows[b].x)+(cows[a].y-cows[b].y)*(cows[a].y-cows[b].y)<=x);
}

bool v[1000];

void dfs(int x, int node){
        v[node]=true;
        for(int i=0; i<n; i++){
                if(!v[i] && transmit(x, i, node)) dfs(x, i);
        }
}
bool ok(int x){
        dfs(x, 0);
        int cnt=count(v, v+1000, true);
        fill(v, v+1000, 0);
        return(cnt==n);
}
signed main(){
        cin.tie(0)->sync_with_stdio(0);
        ifstream cin("moocast.in"); ofstream cout("moocast.out");
        cin>>n;
        for(int i=0; i<n;i ++){
                cin>>cows[i].first>>cows[i].second;
        }

        int lo=1, hi=1296000000;
        int ans;
        while(lo<=hi){
                int x=lo+(hi-lo)/2;
                if(ok(x)){
                        ans=x;
                        hi=x-1;
                }
                else lo=x+1;
        }
        cout<<ans<<endl;
        return 0;
}
