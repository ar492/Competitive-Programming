#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        double n; cin>>n;
        cout<<(int)ceil(n/2)<<endl;///works with int but not otherwise?
    }

    return 0;
}
