#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<char, int> freq;
        string s;
        for(int i=0; i<n; i++){
            cin>>s;
            for(char c:s){
                freq[c]++;
            }
        }
        bool chk=1;
        for(pair<char, int> x:freq){
            if(x.S%n!=0) chk=0;
        }
        cout<<(chk ? "YES" : "NO")<<endl;
    }
return 0;
}
