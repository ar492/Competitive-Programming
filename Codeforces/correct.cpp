#include "bits/extc++.h"
using namespace std; using namespace __gnu_pbds; using ll = long long; using pbds = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>; using vll = vector<ll>; using vvll = vector<vll>;
ll MX = 1e6+1, mod = 1e9+7, inf = 1e18; double eps = 1e-9; void setMod(ll m = 998244353){ mod = m; }
#define endl '\n'
#define test ll cases; cin>>cases; for(ll testCase = 1; testCase <= cases; testCase++)
#define mop(a, op, b) ((a%mod op b%mod) + mod)%mod
/* get(array, n); get(array1, array2, n); get(2D array, n, m); get(...); */ template<typename T> void get(T* a, ll n){ for(ll i = 0; i < n; i++) cin>>a[i]; } template<typename T> void get(vector<T>& a, ll n){ for(ll i = 0; i < n; i++) cin>>a[i]; } template<typename T> void get(T* a, T* b, ll n){ for(ll i = 0; i < n; i++) cin>>a[i]>>b[i]; } template<typename T> void get(vector<T>& a, vector<T>& b, ll n){ for(ll i = 0; i < n; i++) cin>>a[i]>>b[i]; } template<typename T> void get(T** a, ll n, ll m){ for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin>>a[i][j]; } template<typename T> void get(vector<vector<T>>& a, ll n, ll m){ for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin>>a[i][j]; } template <class ...Args> void get(Args &...args){ (cin >> ... >> args); }
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v){ for(auto i = v.begin(); i != v.end(); i++) out<<(*i)<<' '; return out; } template<typename T> ostream& operator<<(ostream& out, const set<T>& s){ out<<'['; for(auto i = s.begin(); i != s.end(); i++) out<<(i!=s.begin()?", ":"")<<(*i); return(out<<']'); } template<typename T1, typename T2> ostream& operator<<(ostream& out, const map<T1, T2>& m){ out<<'{'<<endl; for(auto x : m) out<<"    "<<x.first<<" -> "<<x.second<<endl; return(out<<'}'); } template<typename T> T mpow(T x, ll n){ T ans = 1; while(n){ if(n&1) ans = mop(ans, *, x); n >>= 1, x = mop(x, *, x); } return ans; } ll modinv(ll x){ return mpow(x, mod-2); } vll FACT(1, 1); ll ncr(ll n, ll r){ if(n < r) return 0; while(n >= FACT.size()) FACT.push_back(mop(FACT[FACT.size()-1], *, FACT.size())); return mop(FACT[n],*,mop(modinv(FACT[r]),*,modinv(FACT[n-r]))); } ll fact(ll n){ while(n >= FACT.size()) FACT.push_back(mop(FACT[FACT.size()-1], *, FACT.size())); return FACT[n]; }
void zenit(bool tieIO = 1){ cout<<fixed<<setprecision(9); if(tieIO){ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }} mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string n;	ll k;
vector<vvll> dp, choice;
ll ops = 0;
bool calc(ll i, ll tight, ll mask){
	ops += 10;
	if (__builtin_popcount(mask) > k)	return 0;
	if(i == n.length())	return 1;
	if (dp[i][tight][mask] != -1)	return dp[i][tight][mask];
	ll low = tight ? n[i] - '0' : 0;
	bool ans = 0;
	for(ll j = low; j < 10; j++){
		if(calc(i+1, tight & (j == low), mask | (1 << j))){
			ans = 1;
			choice[i][tight][mask] = j;
			break;
		}
	}
	return dp[i][tight][mask] = ans;
}
int main(){
	zenit();
	test{
		cin>>n>>k;
		dp.clear();	dp.resize(10, vvll(2, vll(1024, -1)));
		choice.clear();	choice.resize(10, vvll(2, vll(1024, -1)));
		calc(0, 1, 0);
		ll i = 0, tight = 1, mask = 0;
		ll ans = 0;
		while(i < n.length()){
			ll low = tight ? n[i] - '0' : 0;
			ll ch = choice[i][tight][mask];
			ans = ans * 10 + ch;
			tight &= (ch == low);
			mask |= 1 << ch;
			i++;
		}
		cout<<ans<<endl;
	}
	cerr << "correct took " << ops << " ops" << endl;
}