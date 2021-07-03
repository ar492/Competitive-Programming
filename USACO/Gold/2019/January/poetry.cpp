#include<bits/stdc++.h>
#define int long long
#define s first
#define c second
using namespace std;

void setIO(string name) {
	cin.tie(0)->sync_with_stdio(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

const int MOD=1e9+7, sz=1e6;
int N, M, K, dp[2*sz];
pair<int, int>  w[sz];
map<int, int> cmps;
vector<int> groups;

int expo(int a, int b){
        int m=1, ans=1;
        for(int i=0; i<=30; i++){
                m*=(m==1 ? a : m); m%=MOD;
                if(b & (1LL<<i)) ans*=m, ans%=MOD;
        }
        return(a ? ans : 0);
}

void knapsack(){
        dp[0]=1;
        for(int pos=0; pos<K; pos++)
                for(int i=0; i<N; i++)
                        dp[pos+w[i].s]= (dp[pos+w[i].s] + dp[pos])%MOD;
        for(int i=0; i<N; i++)
                groups[w[i].c]=(groups[w[i].c]+dp[K-w[i].s])%MOD;
}

void pre(){
        cin>>N>>M>>K;
        groups.resize(N+1, 0);
        for(int i=0; i<N; i++) cin>>w[i].s>>w[i].c;
        for(int i=0; i<M; i++){
                char x; cin>>x; cmps[x-'A']++;
        }
        knapsack();
}


signed main(){
        setIO("poetry");
        pre();
        int ans=1;
        for(auto i:cmps){
                int sum=0;
                for(int x:groups)
                        sum=(sum+expo(x, i.second))%MOD;
                ans=(ans*sum)%MOD;
        }
        cout<<ans<<endl;
}
