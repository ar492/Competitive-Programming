#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
    ll k; cin>>k;
    ll n=1;
    while(pow(n,10)<k){n++;}
    ll p=10;
    cout<<"n is "<<n<<endl;
    string s="codeforces";
    if(pow(n,10)>k){
        cout<<"nope"<<endl;
        for(int i=10; i>=1; i--){
            cout<<((ll)pow(n, i))<<" + "<<(ll)pow(n-1, 10-i)<<" = "<<((ll)pow(n, i)+(ll)pow(n-1, 10-i))<<endl;
            if(((ll)pow(n, i)+(ll)pow(n-1, 10-i))>=k){cout<<"greater than k "<<endl;}else{cout<<"less than k"<<endl;}
        }
        while((((ll)pow(n, p))*((ll)pow(n-1, 10-p))>=k)){cout<<"pow(n,p) = "<<(ll)pow(n,p)<<endl;p--;}
        cout<<"p^8 = "<<p<<"^8 = "<<(ll)pow(p,8)<<endl;
        cout<<"p is "<<p<<endl;
        for(ll i=0;i<=p;i++){
            char c=s[i];
            for(ll j=0;j<n;j++){cout<<c;}
        }
        for(ll i=p+1; i<10; i++){for(int j=0; j<n-1; j++){cout<<s[i];}}
    }
    else{
        for(ll i=0;i<=9;i++){
        char c=s[i];
        for(ll j=0;j<n;j++){cout<<c;}
    }///8^3 * 7^7
    }
return 0;
}
