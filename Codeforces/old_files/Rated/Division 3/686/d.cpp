#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
#define fi first
#define se second

//vectors
using vi = vector<int>;
using vpii = vector<pii>;
using vpll = vector<pll>;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define sort(x) sort(all(x)) //type out sorting for arrays
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie (0)->sync_with_stdio (0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n; ll cn=n;
        ll limit = sqrt (n) + 1;
        vector<ll> ans;
        for (ll i = 2; i <= limit; i++) {
            //if(ans.size()>0 && i%ans.back()!=0) continue;
          //  cout<<"true for i="<<i<<endl;
            if (n < i)
                break;
            if (n % i == 0) {
                while (n % i == 0) {
                    ans.pb (i);
                    //cout<<"pushing "<<i<<endl;
                    n /= i;
                }
            }
        }
        vector<ll> anscopy;
        for(int i=0; i<sz(ans)-1; i++){
            anscopy.pb(ans[i]);
            if(ans[i+1]%ans[i]!=0){
                ll tmp=ans[i+1];
                ll x=ans[i];
                int j=i;
                while(j+1<ans.size() && tmp%x!=0){
                    tmp*=ans[j+1]; j++;
                }
                if(tmp%ans[i])
                anscopy.pb(tmp);

            }
        }
        cout<<"displaying"<<endl;
        bool valid=1; ll tmp=1;
        for(ll i:anscopy){
            tmp*=i;
        }
        cout<<"ans is "<<endl;
        for(ll i: anscopy) cout<<i<<" "; cout<<endl;
        if(tmp!=cn) valid=0;
      //  cout<<"tmp is "<<tmp<<endl;
    //    cout<<"valid is"<<valid<<endl;
        if (anscopy.size() == 0 || !valid)
            cout << "1\n" << cn << endl;
        else {
            cout << anscopy.size() << endl;
            for (ll i : anscopy)
                cout << i << " ";
            cout << endl;
        }
        cout<<"display end"<<endl;
    }
    return 0;
}
