#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);
    long long n, m; cin>>n>>m;
    vector<pair<int,int>> hb(n); //haybales <flavor, spiciness>
    for(int i=0; i<n; i++)
        cin>>hb[i].first>>hb[i].second;
    int l=0; int r=0;
    long long ac=hb[0].first; //accumulation of flavors over window [l,r]
    int mxspice=hb[0].second;
    int mnmxspice=1e9;
    multiset<int> spices;
    spices.insert(hb[0].second);
    while(l<=r){
        if(ac<m){
            r++;
            if(r==n) break;
            ac+=hb[r].first;
            mxspice=max(mxspice, hb[r].second);
            spices.insert(hb[r].second);
        }
        else{
            mnmxspice=min(mnmxspice, mxspice);
            l++;
            if(l==n) break;
            ac-=hb[l-1].first;
            spices.erase(spices.find(hb[l-1].second));
            mxspice=min(mxspice, *(spices.rbegin()));
        }
    }
    cout<<mnmxspice<<endl;
return 0;
}
