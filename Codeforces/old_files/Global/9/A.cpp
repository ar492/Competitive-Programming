#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            int temp; cin>>temp;
            a[i]=abs(temp);
        }
    }
    return 0;
}
