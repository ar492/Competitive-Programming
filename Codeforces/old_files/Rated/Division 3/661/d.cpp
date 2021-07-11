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
        int n; cin>>n;
        string s; cin>>s;
        vector<int> ans;
        stack<int> zeroid;
        stack<int> oneid;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                if(oneid.empty()){
                    cnt++;
                    ans.pb(cnt); zeroid.push(cnt);
                }
                else{
                     zeroid.push(oneid.top()); oneid.pop();
                     ans.pb(zeroid.top());
                }

            }
            else if(s[i]=='1'){
                if(zeroid.empty()){
                    cnt++;
                    ans.pb(cnt); oneid.push(cnt);
                }
                else{
                     oneid.push(zeroid.top()); zeroid.pop();
                     ans.pb(oneid.top());
                }
            }
        }
        cout<<cnt<<endl;
        for(int i:ans)
            cout<<i<<" ";
        cout<<endl;
    }
return 0;
}
