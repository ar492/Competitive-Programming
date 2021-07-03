#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){

    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("pails.in"); ofstream cout("pails.out");
    int x,y,m; cin>>x>>y>>m;
   //ax+by = m
    int mx=0;
    for(int a=0; a<=m/x; a++){
        int b=(m-a*x)/y;
        mx=max(mx, a*x+b*y);
    }
   cout<<mx<<endl;
return 0;
}
