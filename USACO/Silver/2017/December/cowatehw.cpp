#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("homework.in","r",stdin);
    freopen("homework.out","w",stdout);
    int n; cin>>n;
    int m[n]; //suffix minimum val
    fill(m, m+n, 10000);
    int q[n]; //questions
    for(int i=0; i<n; i++) cin>>q[i];
    m[n-1]=q[n-1];
    for(int i=n-2; i>=0; i--){  m[i]=min(m[i+1], q[i]); }
    double a[n]; // raw average
    a[n-1]=q[n-1];
    for(int i=n-2; i>=0; i--)
        a[i]=(a[i+1]*(n-i-1)+q[i])/(n-i);
    double ans[n];
    for(int i=n-2; i>=0; i--)
        ans[i]=(a[i]*(n-i)-m[i])/(n-i-1.0);
    ans[n-1]=0;
    double mx=0;
    for(int i=1; i<n-1; i++) mx=max(ans[i], mx);
    set<int> s;
    for(int i=1; i<n-1; i++)
        if(ans[i]==mx) s.insert(i);
    for(int i:s) cout<<i<<endl;
return 0;
}
