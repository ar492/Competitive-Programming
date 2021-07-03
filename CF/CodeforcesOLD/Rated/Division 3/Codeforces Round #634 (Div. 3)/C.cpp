#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; int a[n];
        set<int> s;
        map<int, int> freq;
        for(int i=0; i<n; i++){ cin>>a[i]; s.insert(a[i]); freq[a[i]]++;}
        int mx=0;
        for(int i:s){
            if(s.size()<freq[i])
                mx=max(mx, (int)s.size());
            else if(s.size()==freq[i]) mx=max(mx, freq[i]-1);
            else mx=max(mx, freq[i]);
        }
        cout<<mx<<endl;
    }
return 0;
}
