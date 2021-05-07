#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
//#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        ll aa,bb; cin>>aa>>bb;
        ll a=min(aa, bb); ll b=max(aa, bb);
        if((a+b)%3==0 && a*2>=b)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
return 0;
}
