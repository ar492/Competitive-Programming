#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

void execute(int n){
    int k=2;
    while(k<=(int)sqrt(n)){
        if(n%k==0){
            cout<<n/k<<" "<<n-n/k<<endl; return;
        }
        k++;
    }
    cout<<1<<" "<<n-1<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n; cin>>n; execute(n);
    }
return 0;
}



