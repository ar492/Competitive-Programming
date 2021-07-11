#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int ocnt(int a, int b, int c, int d){
    int cnt=0;
    if(a%2==1) cnt++;
    if(b%2==1) cnt++;
    if(c%2==1) cnt++;
    if(d%2==1) cnt++;
    return cnt;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int qq=0; qq<t; qq++){
        int r,g,b,w; cin>>r>>g>>b>>w;
        if(ocnt(r,g,b,w)<=1)cout<<"Yes"<<endl;
        else{
            if(ocnt(r-1, g-1, b-1, w+3)<=1 && r>=1 && g>=1 && b>=1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
return 0;
}
