#ifdef LOCAL
#include			<C:\\Users\\gbpol\\Desktop\\Useful\\cp.h>
#else
#include 			<bits/extc++.h> // stdc++
#endif
#define 			int long long
#define 			_ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
using namespace std;

int t;
const int sz=1e7+1;
bool sieve[sz];
vector<int> primes;

signed main(){_
       for(int i=2; i<sz; i++)
              if(sieve[i]==0) // if prime
                     for(int x=2*i; x<sz; x+=i)
                            sieve[x]=1;
       for(int i=2; i<sz; i++)
              if(sieve[i]==0)
                     primes.emplace_back(i);
       cin>>t;
       while(t--){
              int n,k; cin>>n>>k;
              int a[n]; fill(a, a+n, 1);
              for(int i=0; i<n; i++){
                     int num; cin>>num;
                     map<int, int> factors;
                     for(int x:primes){
                            if(x*x>num) break;
                            while(num%x==0){
                                   num/=x; factors[x]++;
                            }
                     }
                     if(num>1) factors[num]++;
                     for(auto &x:factors) a[i]*=(x.second&1 ? x.first : 1);
              }
              set<int> s;
              int ans=1;
              for(int i=0; i<n; i++){
                     if(s.count(a[i])){
                            ans++; s.clear();
                     }
                     s.insert(a[i]);
              }
              cout<<ans<<endl;
       }
}

/*

1
5 0
6 8 1 24 8

*/
