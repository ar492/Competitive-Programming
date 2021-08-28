/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    long long sum=0, ans=-1e14;
    for(int i=0; i<n; i++){
        sum+=a[i];
        ans=max(ans, sum);
        sum=max(0LL, sum);
    }
    cout<<ans<<endl;
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;

int a[200000], p[200000], n, ans=-INT_MAX;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < 2 * n; i++) {
        if(i < n) cin >> a[i];
        else a[i] = a[i - n];
        p[i] = a[i] + p[max(0, i - 1)];
    }
    multiset<int> ms;
    ms.insert(0); //dummy
    for(int i=0; i<2*n; i++) cout<<a[i]<<" "; cout<<endl;
    for(int i=0; i<2*n; i++) cout<<p[i]<<" "; cout<<endl;
    for(int i = 0; i < 2 * n; i++) {
        cout<<"i = "<<i<<endl;
        //cout<<"ms: ";
       // for(auto j:ms) cout<<j<<" "; cout<<endl;
        if(i + 1 > n){ ms.erase(ms.find(p[i-n])); cout<<"erasing "<<p[i-n]<<endl; }
        ans = max(ans, p[i] - *ms.begin());
        cout<<"try : "<<p[i]-*ms.begin()<<endl;
        ms.insert(p[i]);
        cout<<"inserting "<<p[i]<<endl;
        if(!i) ms.erase(ms.find(0));
       // cout<<"ms final: ";
        //for(auto j:ms) cout<<j<<" "; cout<<endl;
    }
    cout << ans << endl;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[1000000], p[1000000], n, ans=-1e18;

int main() {
    ll n;
    cin >> n;
    for(ll i = 0; i < 2 * n; i++) {
        if(i < n) cin >> a[i];
        else a[i] = a[i - n];
        p[i] = a[i] + p[max(0ll, i - 1)];
    }
    multiset<ll> ms;
    ms.insert(0); //dummy
    for(ll i = 0; i < 2 * n; i++) {
        if(i + 1 > n) ms.erase(ms.find(p[i-n]));
        ans = max(ans, p[i] - *ms.begin());
        ms.insert(p[i]);
        if(i==0) ms.erase(ms.find(0ll));
    }
    cout << ans << endl;
    return 0;
}
