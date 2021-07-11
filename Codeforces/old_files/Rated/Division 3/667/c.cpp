#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x,y,t; cin>>t;
    while(t--){
        cin>>n>>x>>y; // x<y
        int mn=2e9;
        set<int> ans;
        for(int i=1; i<50; i++)//choosing starting element
            for(int j=1; j<50; j++){//choosing differences
                int k=0;
                set<int> s;
                while(k<n && s.size()<n){
                    s.insert(i+j*k); k++;
                }
                if(s.count(x) && s.count(y))
                    if(*--s.end()<mn){
                        mn=*--s.end(); ans=s;
                    }
            }
        for(int i:ans) cout<<i<<" ";
        cout<<endl;
    }
return 0;
}
