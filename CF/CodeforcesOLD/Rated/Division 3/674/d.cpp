#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n; long long a[n]; for(long long &x:a) cin>>x;
    set<ll> s; s.insert(0);
    int cnt=0;
    long long p=0;
    for(auto i:a){
        p+=i;
        if(s.count(p)){ cnt++; s.clear(); p=i; s.insert(0);} //o(n)
        s.insert(p); //o(logn)
    }
    cout<<cnt<<endl;
return 0;
}
