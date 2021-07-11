#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; string s; cin>>n>>s;
        s+=s.substr(0, 2);
        int sl=s.length();
        int cnt=0;
        for(int i=0; i<sl-2; i++)
            if(s[i]==s[i+1] and s[i+1]==s[i+2]){ cnt++; i+=2; }
        cout<<cnt<<endl;
    }
return 0;
}
