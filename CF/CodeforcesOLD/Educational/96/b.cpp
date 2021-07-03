#include <bits/stdc++.h>
#define intt long long
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        intt n,k; cin>>n>>k;
        priority_queue<intt> b; //barrels
        for(int i=0; i<n; i++){ int tmp; cin>>tmp; b.push(tmp); }
        intt m=b.top(); b.pop();
        for(int i=0; i<k; i++){
            if(b.empty()) break;
            m+=b.top(); b.pop();
        }
        cout<<m<<endl;
    }
return 0;
}
