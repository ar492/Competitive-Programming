#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        string s=to_string(x);
        cout<<(10*(s[0]-'0'-1)+(s.length())*(s.length()+1)/2)<<endl;
    }
return 0;
}
