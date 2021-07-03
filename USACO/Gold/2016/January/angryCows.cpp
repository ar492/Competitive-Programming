#include<bits/stdc++.h>
using namespace std;
#define index second
#define val first

int n;
vector<int> x, s, p;

int main(){
       ifstream cin("angry.in"); ofstream cout("angry.out");
       cin>>n;
       x.resize(n); s.resize(n); p.resize(n);
       for(int i=0; i<n; i++) cin>>x[i];

       sort(x.begin(), x.end());

       for(int i=n-2; i>=0; i--) s[i]=max(x[i+1]-x[i], s[i+1]+1);
       for(int i=1; i<n; i++) p[i]=max(x[i]-x[i-1], p[i-1]+1);

       set<pair<int, int>, greater<pair<int, int>>> vals;
       set<int> mins;
       for(int i=0; i<n; i++){
              vals.insert({x[i]-2*s[i]+2, i});
              mins.insert(s[i]+1);
       }

       double ans=2e9, mindist=2e9;

       for(int i=n-2; i>=0; i--){ // dist ij increases
              mindist=2e9;
              while(vals.size() && (*vals.begin()).val > x[i]){
                     mndist=min(mndist, x[(*vals.begin()).index]-x[i]);
                     vals.erase(vals.begin());
              }
       }
       for(int i=0; i<n-1; i++)
              ans=min(ans, max(max(p[i], s[i+1])+1.0, (x[i+1]-x[i])/2.0));


       for(int i=1; i<n; i++){
              ans=min(ans, max(p[i], s[i])+0.0);
       }

       cout<<fixed<<setpcision(1)<<ans<<endl;
}
