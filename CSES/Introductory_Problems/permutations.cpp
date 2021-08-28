#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    if(n==1){
        cout<<1<<endl; return 0;
    }
    if(n<=3){
        cout<<"NO SOLUTION"<<endl; return 0;
    }
    if(n==4){
        cout<<"3 1 4 2"<<endl; return 0;
    }
    cout<<ceil(n/2.0)<<" ";
    for(int i=0; i<n-1; i++){
        cout<<(i%2==0 ? n-i/2 : i/2+1)<<" ";
    }
return 0;
}
