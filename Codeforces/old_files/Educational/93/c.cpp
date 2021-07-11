#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; string st; cin>>n>>st;
        //cout<<n<<" "<<st<<endl;
        int a[n];
        for(int i=0; i<n; i++) a[i]=(int)(st[i]-'0'-1);
        for(int i:a) cout<<i<<" "; cout<<endl;
        int p[n]; p[0]=a[0];
        for(int i=1; i<n; i++) p[i]=p[i-1]+a[i];
        //for(int i=0; i<n; i++){
        //    cout<<a[i]<<" ";
        //}cout<<endl;
        //for(int i:p) cout<<p[i]<<" ";
      //  cout<<endl;
        int oc[n];
        fill(oc, oc+n, 0);
        int cnt=count(a, a+n, 0)+count(p, p+n, 0);
        if(a[0]==0) cnt--;
        for(int i=0; i<n; i++) oc[p[i]]++;
        for(int i:oc)
            if(i>1) cnt+=(i)*(i-1)/2;
        cout<<"ans is "<<cnt<<endl;
    }
return 0;
}
