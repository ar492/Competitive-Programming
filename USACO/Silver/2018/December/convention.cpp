#include <bits/stdc++.h>
using namespace std;

int n,m,c; //n cows, m busses, at most c cows per bus
vector<int> times; //arrival times of n cows

bool possible(int mt){ //mt = max wait time for any cow
    int bcnt=1; //# used busses, starts with 1 because at the end it doesnt iterate
    int cindex=0; //which cow is pending, if all are done then cindex=n
    int mn=0; // index of first cow on bus
    for(cindex; cindex<n; cindex++){
        if(times[cindex]-times[mn]>mt || cindex-mn==c){ //bus filled up or mt exceeded
            bcnt++;
            mn=cindex;
        }
    }
    return (bcnt<=m);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    cin>>n>>m>>c;
    times.resize(n);
    for(int i=0; i<n; i++) cin>>times[i];
    sort(times.begin(), times.end());
    int l=0; int r=1e9;
    int ans; //answer
    while(l<=r){
        int m=(l+r)/2;
        if(possible(m)){ ans=m; r=m-1; }
        else l=m+1;
    }
    cout<<ans<<endl;
return 0;
}
