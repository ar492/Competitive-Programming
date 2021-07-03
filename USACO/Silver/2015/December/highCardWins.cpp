#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int cnt, n; string a; string v;

void exe(){
    for(int i=0; i<2*n-1; i++){
        if(a[i]=='1'){
            bool chk=0;
            for(int j=i+1; j<2*n; j++){
                if(a[j]=='0' && v[j]=='0'){
                    //cout<<i<<" "<<j<<endl;
                    cnt++; chk=true; v[j]='1'; break;
                }
            }
            if(chk==false){
                return;
            }
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    a=string(2*n, '0'); v=string(2*n, '0');
    for(int i=0; i<n; i++){
        int x; cin>>x; x--;
        a[x]='1';
    }
    exe();
    cout<<cnt<<endl;


return 0;
}
