#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int i=0; i<t; i++){
        int n; cin>>n;
        set<int> s;
        vector<int> perm;
        for(int j=0; j<2*n; j++){
            int temp; cin>>temp;
            if(!s.count(temp)){
                s.insert(temp);
                perm.pb(temp);
            }
        }
        for(int j=0; j<n; j++){
            cout<<perm[j]<<" ";
        }cout<<endl;
    }
return 0;
}


