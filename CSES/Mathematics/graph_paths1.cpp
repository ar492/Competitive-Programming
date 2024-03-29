
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
	bool operator == (const Matrix & other){ return (m == other.m); }
	Matrix operator + (const Matrix & other){
		Matrix res = other;
		loop(i, r) loop(j, c) res.m[i][j] = (res.m[i][j] + m[i][j]) % mod;
		return res;
	}
	Matrix operator - (const Matrix & other){
		Matrix res = other;
		loop(i, r) loop(j, c) res.m[i][j] = ( - res.m[i][j] + m[i][j] + 5 * mod) % mod;
		return res;
	}
	Matrix operator * (const Matrix & other){//(r1, c1) x (r2, c2) = O(r1 r2 c2) = O(r1 c1 c2), c1 = r2
		assert(c == other.r);
		Matrix prod(r, other.c);
		for (int i = 0; i < r; i++){
			for (int j = 0; j < other.c; j++){
				int sum = 0;
				for (int k = 0; k < c; k++)
					sum = (sum + (m[i][k] * other.m[k][j])%mod) % mod;
				prod.m[i][j] = sum;
			}
		}
		return prod;
	}
	void expo(int p){
		assert(r==c);
		Matrix res(m);
		loop(i, r) loop(j, c) res.m[i][j]=(i==j);
		while (p){
			if (p & 1) res = res * (*this);
			p >>= 1LL;
			(*this)=(*this)*(*this);
		}
		(*this)=res;
	}
};

signed main(){
	int n, m, k; cin >> n >> m >> k;
	Matrix adj(n, n);
	while(m--){
		int u, v; cin >> u >> v; 
		u--; v--;
		adj.m[u][v]++;
	}
	adj.expo(k);
	cout << adj.m[0][n - 1] << endl;
}
