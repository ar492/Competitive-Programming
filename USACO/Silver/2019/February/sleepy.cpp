#include <bits/stdc++.h>
using namespace std;

int n; int line[(int)1e5+1];

void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++) cin>>line[i];
    sort(line, line+n);
}

int mxFind(){
    int ans=0;
    for(int i=1; i<n; i++)
        ans+=line[i]-line[i-1]-1;
    return (ans-min(line[n-1]-line[n-2], line[1]-line[0])+1);
}

int mnFind(){
    int ans=0;
    int r=0;
    for(int l=0; l<n; l++){
        while(r+1<n && line[r+1]-line[l]<=n-1){
            r++;
        }
        ans=max(ans, r-l+1);
    }
    if(ans==n-1&&(line[n-1]-line[1]==n-2&&line[1]-line[0]!=2||line[n-2]-line[0]==n-2&&line[n-1]-line[n-2]!=2)) return 2;
    return n-ans;
}
int main(){
    setup();
    cout<<mnFind()<<"\n"<<mxFind()<<"\n";

return 0;
}
