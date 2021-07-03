#include <bits/stdc++.h>
using namespace std;

vector<int> hl;
vector<bool> v; //haylocations, visited
int n;
int cntMax;

void cnt(){
	cntMax = max(cntMax, count(v.begin(), v.end(), 1));
	replace(v.begin(), v.end(), 1, 0);
}

void exe(int hindex, int r){
	v[hindex] = 1;
	vector<int> t;
	for (int i = 0; i < n; i++)
		if (abs(hl[i] - hl[hindex]) <= r && v[i] == 0){
			v[i] = 1;
			t.push_back(i);
		}
	for (int i : t) exe(i, r + 1);
}
int main(){
	ifstream cin("angry.in"); ofstream cout("angry.out");
	cin >> n;
	hl.resize(n);
	v.resize(n, 0);
	for (int i = 0; i < n; i++) cin >> hl[i];
	sort(hl.begin(), hl.end());
	for (int i = 0; i < n; i++){
		exe(i, 1); cnt();
	}
	cout << cntMax << endl;
	return 0;
}
