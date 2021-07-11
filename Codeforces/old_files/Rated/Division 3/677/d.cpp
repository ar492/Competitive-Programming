#include <bits/stdc++.h>
#define F first
#define S second
#define B begin()
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int, set<int>> d; //<district#, indices in a>
        set<int> s;
        int a[n]; for(int i=0; i<n; i++){ cin>>a[i]; d[a[i]].insert(i+1); s.insert(a[i]); }
        if(s.size()==1) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            int prev=*(d.B->S).B;
            (d.B->S).erase(prev);
            int pd=(d.B->F); //prev district
            for(pair<int, set<int>> i:d){
                if(i.F!=pd)
                    for(int x:i.S) cout<<prev<<" "<<x<<endl;
            }
            for(int i:(d.B->S))
                cout<<*((++d.B)->S).B<<" "<<i<<endl;
        }
    }
return 0;
}
