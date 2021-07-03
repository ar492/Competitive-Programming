#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("pairup.in","r",stdin);
    freopen("pairup.out","w",stdout);
    int n; cin>>n;
    vector<pair<int,int>> pairs(n); // <milk output, # cows with that milk output>
    int np=0; //number of pairs
    for(int i=0; i<n; i++){
        cin>>pairs[i].second>>pairs[i].first;
        np+=pairs[i].second;
    }
    np/=2;
    sort(pairs.begin(), pairs.end());
    int l=0; int r=n-1;
    int mx=0;
    int nd=0; //nd is # pairs done/sent
    while(nd!=np){
        mx=max(mx, pairs[l].first+pairs[r].first);
        if(pairs[l].second > pairs[r].second){
            nd+=pairs[r].second;
            pairs[l].second-=pairs[r].second;
            r--;
        }
        else if(pairs[l].second < pairs[r].second){
            nd+=pairs[l].second;
            pairs[r].second-=pairs[l].second;
            l++;
        }
        else{
            nd+=( l==r ? pairs[r].second/2 : pairs[r].second );
            l++; r--;
        }
    }
    cout<<mx<<endl;
return 0;
}
