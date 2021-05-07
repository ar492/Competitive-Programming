#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    string s; cin>>s;
    int cur=0; int m=0;
    while(cur!=s.length()){
        char orig=s[cur];
        int cnt=0;
        while(s[cur]==orig)
            {cnt++; cur++;}
        m=max(m,cnt);
    }
    cout<<m<<endl;
return 0;
}
