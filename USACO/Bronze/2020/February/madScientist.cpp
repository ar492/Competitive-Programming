#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("breedflip.in","r",stdin);
    freopen("breedflip.out","w",stdout);
    int n; cin>>n;
    vector<bool> d(n, 0);
    string a,b; cin>>a>>b;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(a[i]!=b[i]){
            cnt++;
            while(i<n && a[i]!=b[i]) i++;
        }
    }
    cout<<cnt<<endl;
return 0;
}
