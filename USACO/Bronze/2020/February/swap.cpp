#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("swap.in","r",stdin);
  //  freopen("swap.out","w",stdout);
    int n,k; cin>>n>>k;
    int a[n];
    iota(a, a+n, 1);
    pair<int,int> op1,op2;
    cin>>op1.first>>op1.second>>op2.first>>op2.second;
    int cnt=0;
    while(true){
        cnt++;
        reverse(a+op1.first-1, a+op1.second);
        reverse(a+op2.first-1, a+op2.second);
        bool c=1;
        for(int i=0; i<n; i++){
            if(a[i]!=i+1){ c=0; break; }
        }
        if(c) break;
    }
    k%=cnt;
    for(int i=0; i<k; i++){
        reverse(a+op1.first-1, a+op1.second);
        reverse(a+op2.first-1, a+op2.second);
    }
    for(int i=0; i<n; i++) cout<<a[i]<<"\n";
return 0;
}
