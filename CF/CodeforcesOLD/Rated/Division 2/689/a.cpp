#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
#define fi first
#define se second

//vectors
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define all(x) (x).begin(), (x).end()
#define sort(x) sort(all(x)) //type out sorting for arrays
#define pb push_back

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define TCASES int testcases; cin>>testcases; while(testcases--)

#define print(x) cout<<x<<"\n";
void printv(vector<ll> v, int sz){
    for(int i=0; i<sz; i++)
        cout<<v[i]<<" ";
    cout<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);


    TCASES{
        int n,k;
        cin>>n>>k;
        char c='a';
        for(int i=0; i<n; i++){
            cout<<c;
            if(c=='c') c='a';
            else c++;
        }cout<<endl;

    }
return 0;
}
