#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int i=0; i<t; i++){
        int n; cin>>n;
        ll counter=0;
        while(n!=1){
            if(n%6==0){n/=6; counter+=1;}
            else if(n%3==0){n/=3; counter+=2;}
            else if ((2*n)%3==0){n*=2; n/=3; counter+=3;}
            else{counter=-1; break;}
        }
        cout<<counter<<endl;
    }
return 0;
}
