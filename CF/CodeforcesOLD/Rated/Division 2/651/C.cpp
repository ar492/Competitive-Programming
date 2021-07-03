#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

ll turncounter=0;
execute(ll n){
if(n==1){///cout<<"turncounter is "<<turncounter<<endl;
if(turncounter%2==0){cout<<"FastestFinger"<<endl;}
else if(turncounter%2==1){cout<<"Ashishgup"<<endl;}

}
else{
   /// cout<<"n is "<<n<<endl;
    ll divisor=-1;
    if(n%2==1){divisor=n;}
    else if(n%2==0){
    for(ll i=n/2; i>1; i--){
        if(i%2==1 && n%i==0){divisor=i; break;}
    }
    }
    ///cout<<"divisor is "<<divisor<<endl;
    if(divisor==-1){turncounter++; execute(n-1);}
    else if (divisor!=-1){
        turncounter++; execute(n/divisor);
    }
   /// cout<<"turncounter is "<<turncounter<<endl;
}
}
int main(){
int t; cin>>t;
for(int i=0; i<t; i++){
    ll n; cin>>n;
    execute(n);
    turncounter=0;
}
return 0;
}
