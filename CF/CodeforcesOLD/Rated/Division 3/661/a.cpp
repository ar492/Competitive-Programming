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
    int t; cin>>t;
    for(int qq=0; qq<t; qq++){
        int n; cin>>n; int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        multiset<int> s;
        for(int i=0; i<n; i++)
            s.insert(a[i]);
       // for(auto it=s.begin(); it!=s.end(); it++)
       //     cout<<*it<<" ";
       // cout<<endl;
        string ans="YES";
        while(s.size()!=1){
            int x=*s.begin();
            s.erase(s.begin());
        //    cout<<"start set:"<<endl;
         //   for(auto it=s.begin(); it!=s.end(); it++)
          //      cout<<*it<<" ";
          //  cout<<endl;
          //  cout<<"end set"<<endl;
          //  cout<<"count "<<x+1<<" is "<<s.count(x+1)<<endl;
          //  cout<<"count "<<x<<" is "<<s.count(x)<<endl;
          //  cout<<"count "<<x-1<<" is "<<s.count(x-1)<<endl;
            if(s.count(x+1) || s.count(x)){

            }
            else{
                ans="NO"; break;
            //    cout<<"for "<<x<<" break"<<endl; ans="NO"; break;
            }
        }

        cout<<ans<<endl;
    }
return 0;
}
