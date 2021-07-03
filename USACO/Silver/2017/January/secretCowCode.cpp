#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string s; ll l; char ans;
void exe(ll n){
    if(n<=l) ans=s[n-1];
    else{
        ll k=1;
        while(k*l < n) k*=2;
        if(n==(k/2)*l+1)//first char of block
            exe(n-1);
        else //not first char of block
            exe(n-((k/2)*l+1));
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("cowcode.in"); ofstream cout("cowcode.out");
    ll n;
    cin>>s>>n; l=s.length();
    exe(n);
    cout<<ans<<endl;
return 0;
}
