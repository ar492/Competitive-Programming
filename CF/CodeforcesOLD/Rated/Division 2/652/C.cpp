#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
int t; cin>>t;
for(int q=0; q<t; q++){
    int n,k; cin>>n>>k;///integers, friends
    vector<int> has;
    vector<int> give;
    for(int i=0; i<n; i++){
        int temp; cin>>temp; has.pb(temp);
    }
    for(int i=0; i<k; i++){
        int temp; cin>>temp; give.pb(temp);
    }
    sort(has.begin(), has.end()); sort(give.begin(), give.end());
        for(int i=0; i<n; i++){
        cout<<has[i]<<" ";
    }cout<<endl;
    for(int i=0; i<k; i++){
        cout<<give[i]<<" ";
    }cout<<endl;
}///wants to give all the integers away
return 0;
}
