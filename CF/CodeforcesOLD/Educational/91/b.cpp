#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

void rep(int l, char b){
    string s(l, b); cout<<s<<endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        string s; cin>>s;
        int rc=count(s.begin(), s.end(), 'R');
        int pc=count(s.begin(), s.end(), 'P');
        int sc=count(s.begin(), s.end(), 'S');
        int m=max(rc, max(pc, sc));
        if(m==rc)
            rep(s.length(), 'P');
        else if (m==pc)
            rep(s.length(), 'S');
        else if (m==sc)
            rep(s.length(), 'R');
    }
return 0;
}
