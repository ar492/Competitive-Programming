#include <bits/stdc++.h>
using namespace std;

void exe(int n){
    if(n==1){
        cout<<"Bob"<<endl; return;
    }
    if(n==2){
        cout<<"Alice"<<endl; return;
    }
    if(n==3){
        cout<<"Bob"<<endl; return;
    }
    if(n==4){
        cout<<"Draw"<<endl; return;
    }
    cout<<"Bob"<<endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        exe(n);
    }
return 0;
}
