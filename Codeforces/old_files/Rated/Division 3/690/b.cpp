#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;

void exe(){
        int n; cin>>n;
        string s; cin>>s;
        int sz=s.length()-1;
        if(s.substr(0, 4)=="2020" || s.substr(sz-3, 4)=="2020") cout<<"YES"<<endl;
        else if(s[0]=='2' && s.substr(sz-2, 3)=="020") cout<<"YES"<<endl;
        else if(s[0]=='2' && s[1]=='0' && string()+s[sz-1]+s[sz]=="20") cout<<"YES"<<endl;
        else if(s[0]=='2' && s[1]=='0' && s[2]=='2' && s[sz]=='0') cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);
    int t; cin>>t;
    while(t--){
        exe();
    }
return 0;
}


