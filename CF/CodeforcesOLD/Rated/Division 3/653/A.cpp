#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int t; cin>>t;
for(int i=0; i<t; i++){
    int x, y, n; cin>>x>>y>>n;
    if(n%x<y){cout<<n-x+(y-n%x)<<endl;}
    else{cout<<n-(n%x-y)<<endl;}
}
return 0;
}
