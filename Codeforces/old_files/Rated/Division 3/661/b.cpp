#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin>>t;
    for(ll qq=0; qq<t; qq++){
        ll n; cin>>n;
        ll a[n]; ll b[n];
        ll ma=INF; ll mb=INF;
        for(ll i=0; i<n; i++){
            cin>>a[i];
            ma=min(a[i], ma);
        }
        for(ll i=0; i<n; i++){
            cin>>b[i];
            mb=min(b[i], mb);
        }
        ll cnt=0;
        for(ll i=0; i<n; i++){
            if(a[i]>ma && b[i]>mb){
                //cout<<"treu"<<endl;
                cnt+=min(a[i]-ma, b[i]-mb);
               // cout<<"a[i] is "<<a[i]<<" and b[i] is "<<b[i]<<endl;
               // cout<<"adding "<<min(a[i]-ma, b[i]-mb)<<endl;
                if(max(a[i]-ma, b[i]-mb)==a[i]-ma){
                //    cout<<"adding "<<(a[i]-min(a[i]-ma, b[i]-mb)-ma)<<endl;
                    cnt+=(a[i]-min(a[i]-ma, b[i]-mb)-ma);
                }
                else if(max(a[i]-ma, b[i]-mb)==b[i]-mb){
                //    cout<<"adding "<<(b[i]-min(a[i]-ma, b[i]-mb)-mb)<<endl;
                    cnt+=(b[i]-min(a[i]-ma, b[i]-mb)-mb);
                }
            }
            else if (a[i]>ma && b[i]==mb){
                //cout<<"a[i] is "<<a[i]<<" and b[i] is "<<b[i]<<endl;
                //cout<<"adding2 "<<a[i]-ma<<endl;
                cnt+=a[i]-ma;
                //cout<<"true2"<<endl;
            }
            else if (b[i]>mb && a[i]==ma){
               // cout<<b[i]<<" > "<<mb<<" && "<<a[i]<<" <= "<<ma<<endl;
            //    cout<<"a[i] is "<<a[i]<<" and b[i] is "<<b[i]<<endl;
             //   cout<<"adding3 "<<b[i]-mb<<endl;
                cnt+=b[i]-mb;
                //cout<<"treu3"<<endl;
            }

        }
        cout<<cnt<<endl;
    }
return 0;
}
