#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

struct minim{
ll loc;
ll val;
};
int main(){
int n,k; cin>>n>>k;
vector<ll> a;
for(int i=0;i<n;i++){
    int temp; cin>>temp; a.pb(temp);
}
///if(k%2==0){
        minim mymin;
        mymin.val=1000000001;
    for(int i=0; i<a.size()-(k)+1; i++){///0 to 3 inclusive
        ll accum1=0;
        ll accum2=0;
        cout<<"i,k is "<<i<<","<<k<<endl;
        cout<<"going from : a["<<i<<"] to a["<<i+k-1<<"] (incrementing by 2)"<<endl;
        for(int j=0;j<k; j+=2){
            ///if(i+j<k){
            cout<<"at a["<<i+j<<" now"<<endl;
            accum1=max(a[i+j], accum1);
            cout<<"accum1 is "<<accum1<<endl;
            ///}
        }
            for(int j=1;j<k; j+=2){
       ///     if(i+j<k){
            cout<<"at a["<<i+j<<" now"<<endl;
            accum2=max(a[i+j], accum2);
            cout<<"accum2 is "<<accum2<<endl;
       //     }
        }
        accum1=min(accum1, accum2);
        cout<<" at end accum1 is "<<accum1<<endl;
            if(min(mymin.val, accum1)==accum1){
        mymin.val=accum1;
        mymin.loc=i;
            }
    }

    cout<<"mymin.val is "<<mymin.val<<endl;
    cout<<"mymin.loc is "<<mymin.loc<<endl;
    cout<<mymin.val<<endl;
///}
/*
9 6
61893 41300 6953 17157 3356 96839 77399 31252 37704
*/
return 0;
}
