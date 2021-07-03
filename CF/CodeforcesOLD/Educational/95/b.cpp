#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];
        int l[n]; // 0 is unlocked 1 is locked
        for(int i=0; i<n; i++) cin>>l[i];
        deque<int> s;
        for(int i=0; i<n; i++)
            if(l[i]==0)
                s.push_back(a[i]);
        sort(s.begin(), s.end(), greater<>());
        for(int i=0; i<n; i++){
            if(l[i]==0){
                a[i]=s[0]; s.pop_front();
            }
        }
        for(int i:a) cout<<i<<" ";
        cout<<"\n";

    }
return 0;
}
