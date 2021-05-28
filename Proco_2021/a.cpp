using namespace std;
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
signed main(){_
       int s,n; cin>>s>>n;
       map<int, int> freq;
       for(int i=0; i<n; i++){
              int x; cin>>x; freq[x]++;
       }
       
       int pref=0;
       for(auto &i:freq){
              int temp=i.second;
              i.second+=pref;
              pref+=temp;
       }
       vector<pair<int, int>> np;
       for(auto i:freq){
              np.push_back({i.second, i.first});
       }
       if(np.back().second!=s) np.push_back({np.back().first, s});
       sort(all(np));
       /*
       for(auto i:np){
              cout<<i.first<<" "<<i.second<<endl;
       }
       */
     //  what((upper_bound(all(np), pair<int, int>(6, 0))-np.begin()));
       int q; cin>>q;
       while(q--){
              int x; cin>>x;
              auto it=upper_bound(all(np), pair<int, int>(x, (int)2e18));
              
              if(it==np.end()){ cout<<s<<nl; continue; }
              if(it==np.begin()){ cout<<0<<nl; continue; }
              else{
                     cout<<(np[(it-np.begin()-1)].second)<<nl;
              }

       }

}