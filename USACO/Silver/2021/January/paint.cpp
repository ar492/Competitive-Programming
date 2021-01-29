#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+2;
int n,q; string f;
int p[sz], s[sz];
vector<int> indices[100];

bool mid(char i, bool prefix){ // if there is element from prev occurrence of i to current occurrence thats less than it
        for(char x='A'; x<i; x++){
                if(!indices[x].size()) continue;
                if(prefix && indices[x].back()>indices[i].back()) return true;
                else if(!prefix && indices[x].back()<indices[i].back()) return true;
        }
        return false;
}

int main(){
        cin>>n>>q>>f;
        f.insert(0,  " "); f.insert(n+1,  " ");
        for(int i=1; i<=n; i++){
                p[i]=p[i-1];
                if(!indices[f[i]].size()) p[i]++; // not seen before
                else p[i]+=mid(f[i], true);
                indices[f[i]].push_back(i);
        }
        for(int i=0; i<100; i++) indices[i].clear();
        for(int i=n; i>=1; i--){
                s[i]=s[i+1];
                if(!indices[f[i]].size()) s[i]++; // not seen before
                else s[i]+=mid(f[i], false);
                indices[f[i]].push_back(i);
        }
        while(q--){
                int a,b; cin>>a>>b;
                cout<<p[a-1]+s[b+1]<<'\n';
        }
}
