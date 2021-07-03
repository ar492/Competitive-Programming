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
    //ifstream cin("inp.txt");
    int n; cin>>n;
    int a[n];
    int no=0;
    for(int q=0; q<n; q++){
      cin>>a[q];
      if(abs(a[q])%2==1){
        no++;
      }
    }
    int oc=0;
    for(int i=0; i<n; i++){
      if(abs(a[i]%2)==1 && oc<no/2){
          if(a[i]>0){
            cout<<a[i]/2+1<<endl;
          }
          else{
            cout<<a[i]/2<<endl;
          }
        oc++;
      }
      else{
        if(a[i]<0 && abs(a[i]%2)==1) cout<<a[i]/2-1<<endl;
        else cout<<a[i]/2<<endl;
      }
    }

return 0;
}
