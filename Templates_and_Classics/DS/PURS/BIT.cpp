// https://cses.fi/problemset/task/1648/
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int sz = 2e5 + 5;

int n, q;
int x[sz];

namespace BIT{
       int bit[sz];
       int psum(int x, int sum=0){ for(; x>0; x-=x&-x) sum+=bit[x]; return sum; } // prefix sum
       int sum(int a, int b){ return(psum(b)-psum(a-1)); } // inclusive, sum of range
       void add(int x, int val){ for(; x<sz; x+=x&-x) bit[x]+=val; }
       void change(int x, int val){ add(x, val-(psum(x)-psum(x-1))); }
}using namespace BIT;

signed main() {
       cin >> n >> q;
       for(int i = 1; i <= n; i++) cin >> x[i], add(i, x[i]);

       for(int i = 1; i <= q; i++) {
              int t, a, b; cin >> t >> a >> b;
              if (t == 1) {
                     add(a, -x[a]); // remove its current value
                     x[a] = b;
                     add(a, x[a]); // add its new value
              }
              else cout << psum(b) - psum(a - 1) << "\n";
       }
}
