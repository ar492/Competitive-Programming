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
#define int long long

int mx, mn;
signed main(){_
       int n; cin>>n;
       int a[n];
       
       for(int i=0; i<n; i++) cin>>a[i], mx+=a[i];
       for(int i:a) mn^=i;
       cout<<mx-mn<<endl;
}