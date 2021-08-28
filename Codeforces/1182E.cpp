#include<bits/stdc++.h>
using namespace std;
#define int long long

#define loop(x, N) for (int x = 0; x < N; x++)

const int mod = 1e9 + 7;
struct Matrix{
	int r, c; vector < vector < int >> m;
	Matrix(){}
	Matrix(int rr, int cc){
		r = rr, c = cc;
		m.assign(r, vector < int > (c, 0));
	}
	Matrix(vector < vector < int >> e){
		m = e;
		r = (int)(e.size());
		c = (int)(e[0].size());
	}
	Matrix operator * (const Matrix & other){//(r1, c1) x (r2, c2) = O(r1 r2 c2) = O(r1 c1 c2), c1 = r2
		assert(c == other.r);
		Matrix prod(r, other.c);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < other.c; j++)
				for (int k = 0; k < c; k++)
					prod.m[i][j] = (prod.m[i][j] + (m[i][k] * other.m[k][j]) % (mod - 1)) % (mod - 1);
		return prod;
	}
	void expo(int p){
		assert(r == c);	Matrix res(m);
		loop(i, r) loop(j, c) res.m[i][j] = (i == j);
		while (p){
			if (p & 1) res = res * ( * this);
			p >>= 1LL;
			( * this) = ( * this) * ( * this);
		}
		( * this) = res;
	}
};

int nexpo(int a, int b){
	if (a == 0) return b == 0;
	int ans = 1;
	while (b){
		if (b & 1) ans = (ans * a) % mod;
		b >>= 1LL;
		a = (a * a) % mod;
	}
	return ans;
}

signed main(){
	int n, f1, f2, f3, c;
	cin >> n >> f1 >> f2 >> f3 >> c;
	Matrix m({{0, 1, 0}, {0, 0, 1}, {1, 1, 1}}), 
	w({{1}, {2}, {4}}), 
	x({{1}, {2}, {3}}), 
	y({{1}, {1}, {2}}), 
	z({{2}, {6}, {14}, {1}, {7}}), 
	m2({
		{0, 1, 0, 0, 0}, 
		{0, 0, 1, 0, 0}, 
		{1, 1, 1,  - 6, 2}, 
		{0, 0, 0, 1, 0}, 
		{0, 0, 0, 1, 1}
	});
	m.expo(max(1ll, n - 4));
	m2.expo(max(1ll, n - 4));
	int ans = 0;
	if(n == 4){
		ans = nexpo(f1, y.m[0][0]) * nexpo(f2, x.m[0][0]) % mod * nexpo(f3, w.m[0][0]) % mod;
		cout << ans * c % mod * c % mod << endl;
		return 0;
	}
	ans = nexpo(f1, (m * y).m[0][0]) * nexpo(f2, (m * x).m[0][0]) % mod * nexpo(f3, (m * w).m[0][0]) % mod;
	if(c == 1){
		cout << ans << endl;
		return 0;
	}	
	cout << (ans * nexpo(c, (m2 * z).m[0][0]) % mod) << endl;

}
