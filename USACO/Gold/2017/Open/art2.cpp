#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct color{
       int h, freq;
       bool operator<(const color & other) const{
              if(freq==other.freq) return h<other.h;
              return freq>other.freq;
       }
};
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	ifstream cin("art2.in"); ofstream cout("art2.out");
	int n; cin>>n;

}

// actually read tips.txt


/*

impossible construction:

 __    __
|  |  |  |
|  |  |  |
|  |__|  |
|________|

*/
