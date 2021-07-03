#include <bits/stdc++.h>
using namespace std;

int arr[1002][1002];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);

    int n,k; cin>>n>>k;
    for(int i=0; i<n; i++){
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        arr[x1][y1]+=1; arr[x2][y2]+=1;
        arr[x1][y2]-=1; arr[x2][y1]-=1;
    }
    for(int i=1; i<1002; i++){
        arr[0][i]+=arr[0][i-1];
        arr[i][0]+=arr[i-1][0];
    }
    for(int i=1; i<1002; i++)
        for(int j=1; j<1002; j++)
            arr[i][j]+=(arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1]);
    int cnt=0;
    for(int i=0; i<1002; i++)
        for(int j=0; j<1002; j++)
            if(arr[i][j]==k) cnt++;
    cout<<cnt<<endl;
return 0;
}
