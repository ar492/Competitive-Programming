#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

void exe(string a, string b, string c){
    for(int i=0; i<a.length(); i++){
        if(!(a[i]==c[i] || b[i]==c[i])){
            cout<<"NO"<<endl; return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int i=0; i<t; i++){
        string a,b,c; cin>>a>>b>>c;
        exe(a,b,c);
    }
return 0;
}
