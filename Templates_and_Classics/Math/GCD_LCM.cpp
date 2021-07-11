#include<bits/stdc++.h>
using namespace std;

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}
int lcm (int a, int b) {
	return a / gcd(a, b) * b;
}

signed main(){
	cout << gcd(6, 4) << " " << lcm(4, 6) << endl;
}