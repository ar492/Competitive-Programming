#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
for(int k=0;k<5;k++){
ll n; cin>>n;
ll i=0;
while((i*(i+1)/2)<n){
    i++;
}
if((i*(i+1)/2)==n){cout<<i<<endl;}
else{
    cout<<i-((i*(i+1)/2)-n)<<endl;

}
cout<<"i is "<<i<<endl;
}
return 0;
}
