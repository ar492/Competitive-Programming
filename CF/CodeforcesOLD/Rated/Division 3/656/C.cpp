#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0; cin>>t;
    for (int q=0; q<t; q++){
        int n; cin>>n; vector<int> a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        int cur=n-1;
        while(a[cur]<=a[cur-1] && cur-1>=0)
            cur--;
        while(a[cur]>=a[cur-1] && cur-1>=0)
            cur--;
        cout<<cur<<endl;
    }
return 0;
}
