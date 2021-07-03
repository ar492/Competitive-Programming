#include <bits/stdc++.h>
using namespace std;

int x1,y1,x2,y2,n;
string s;

vector<pair<int,int>> prefix;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>x1>>y1>>x2>>y2;
    cin>>n>>s; prefix.resize(n, {0,0});
    if(s[0]=='U') prefix[0]={0, 1};
    else if(s[0]=='D') prefix[0]={0, -1};
    else if(s[0]=='L') prefix[0]={-1, 0};
    else prefix[0]={0, 1};
    for(int i=1; i<n; i++){
        int u=0, v=0;
        if(s[i]=='U') v++;
        else if(s[i]=='D') v--;
        else if(s[i]=='R') u++;
        else u--;
        prefix[i]={prefix[i-1].first+u, prefix[i-1].second+v};
    }
    cout<<"prefix: "<<endl;
    for(auto i:prefix) cout<<i.first<<" "<<i.second<<endl;
    int lo=0; int hi=2e9; //over num days
    while(lo<=hi){
        int m=lo+(hi-lo)/2;
    }
return 0;
}
