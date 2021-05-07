#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin>>s;
    vector<string> v;
    sort(s.begin(), s.end());
    do{
       v.pb(s);
    }while(next_permutation(s.begin(), s.end()));
    cout<<v.size()<<endl;
    for(string i:v) cout<<i<<endl;
return 0;
}
