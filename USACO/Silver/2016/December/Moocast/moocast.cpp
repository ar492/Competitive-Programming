#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

ifstream fin("moocast.in");
ofstream fout("moocast.out");

struct cow{
    ll x; ll y; ll p;
};
bool transmit(cow a, cow b){//transmit from a to b
    ll x1=a.x; ll y1=a.y; ll x2=b.x; ll y2=b.y; ll power=a.p;
    if (abs(x2-x1)>power || abs(y2-y1)>power){return false;}
    else if (power*power>=abs(x2-x1)*abs(x2-x1)+abs(y2-y1)*abs(y2-y1)){return true;}
    else{return false;}
}

bool visited[201]={false};
vector<vector<ll>> A;
ll cnt=1;
void dfs(ll u){
    visited[u]=true;
    for(ll i=0; i<A[u].size(); i++){
        if(!visited[A[u][i]]){
            cnt++;
            dfs(A[u][i]);
        }
    }
}

int main(){
    ll n; fin>>n;
    vector<cow> cows(n); A.resize(n);
    for(ll i=0; i<n; i++)
        fin>>cows[i].x>>cows[i].y>>cows[i].p;
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            if(transmit(cows[i],cows[j]))
                A[i].pb(j);
            if(transmit(cows[j],cows[i]))
                A[j].pb(i);
        }
    }
    ll m=1;
    for(ll i=0; i<n; i++){
        if(!visited[i]){
            cnt=1; dfs(i);
        }
        m=max(m, cnt);
        for(int k=0; k<201; k++)
            visited[k]=false;
    }
    fout<<m<<"\n";
return 0;
}
