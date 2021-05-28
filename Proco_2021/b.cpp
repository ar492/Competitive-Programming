using ll=long long;using namespace std;
#ifdef LOCAL
#include<cp.h>
#else
#include<bits/extc++.h>
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v)
{for(int i=0;i<(int)v.size();i++)cout<<v[i]<<(i==(int)v.size()-1?"":" ");return os;}
#endif
#define priority_queue std::priority_queue
#define size(X) ((int)(x.size()))
#define all(X) (X).begin(),(X).end()
#define _ cin.tie(0)->sync_with_stdio(0);cin.exceptions(ios_base::failbit);
#define nl "\n"

signed main(){_
       int n; cin>>n;
       int a[n];
       for(int i=0; i<n; i++){
              cin>>a[i];
       }
       int ans1=0;
       for(int i=0; i<n; i++){
              if(i%2==0 && a[i]%2!=0) ans1++;
              if(i%2==1 && a[i]%2!=1) ans1++;
       }
       int ans2=0;
       for(int i=0; i<n; i++){
              if(i%2==0 && a[i]%2==0) ans2++;
              if(i%2==1 && a[i]%2==1) ans2++;
       }
       cout<<min(ans1, ans2)<<endl;
}