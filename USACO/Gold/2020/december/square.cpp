#include<bits/stdc++.h>
using namespace std;
#define sz(X) (int)((X).size())
#define all(X) (X).begin(), (X).end()
#define ll long long
using namespace std;

short n, vsz;
array<int, 2> pts[201], v[201]; // v is temp pts

inline ll getrand(ll a, ll b){ /// getrandom uniform int in [a, b]
	return(((double)rand() / ((ll)RAND_MAX + 1)) * (b - a + 1) + a);
}
// putting the hash stuff in a namespace makes it slower
unordered_set<ll> hashes;
ll xors[201];
map<array<int, 2>, ll> mp;

inline void setup_hash(){
	for (short j = 0; j < n; j++)
		mp[pts[j]] = getrand(2, 1e13);
}

inline void make_hash(){
	for (short i = 0; i < vsz; i++){
		xors[i] = mp[v[i]];
		if (i) xors[i] = (xors[i - 1] ^ xors[i]);
	}
}

inline ll get_hash(short a, short b){ // [a,b]
	return xors[b] ^ (a ? xors[a - 1] : 0);
}

inline bool cmp(array<int, 2>& a, array<int, 2>& b){
	return a[1] < b[1];
}

void rotate(){
	map<array<int, 2>, ll> mpc = mp;
	mp.clear();
	for (short j = 0; j < n; j++){
		auto& i = pts[j];
		swap(i[0], i[1]);
		i[0] = -i[0];
		mp[i] = mpc[{i[1], -i[0]}];
	}
}

void exe(){
	for (short i = 0; i < n; ++i){
		for (short j = i + 1; j < n; ++j){
			array<int, 2> l = pts[i], r = pts[j];
			int sidelen = r[0] - l[0] + 1, cur = -1;
			for (short k = 0; k < n; ++k)
				if (pts[k][0] >= l[0] and pts[k][0] <= r[0]) // pt x is in the vertical window
					v[++cur] = pts[k];
			vsz = cur + 1;
			sort(v, v + vsz, cmp);
			make_hash();
			for (short lo = 0; lo < vsz; ++lo){ // horizontal lines
				for (short hi = lo; hi < vsz; ++hi){
					if (v[hi][1] - v[lo][1] + 1 > sidelen) break;
					if (lo == 0 or hi == vsz - 1 // cluster is at the very top or bottom of the window
						or v[hi + 1][1] - v[lo - 1][1] + 1 >= sidelen + 2) // cluster is in the middle with enough vertical padding
						hashes.insert(get_hash(lo, hi));
				}
			}
		}
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); //cin.exceptions(ios_base::failbit);
	srand(0); // deterministic per usaco rules
	cin >> n;
	for (short i = n; i--;) cin >> pts[i][0] >> pts[i][1];

	sort(pts, pts + n);
	setup_hash();

	exe();
	rotate(); sort(pts, pts + n); exe();

	cout << sz(hashes) + 1 << endl;
}

/*


4
2 2
4 5
7 4
1 3
15

*/
