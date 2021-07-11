#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    int line[n];
    for(int i=0; i<n; i++) cin>>line[i];
    int lcnt=1;
    for(int i=0; i<n-1; i++){
        if(line[i]<=line[i+1]) lcnt++;
        else break;
    }
    int rcnt=1;
    for(int i=n-1; i>=0; i--){
        if(line[i]<=line[i-1]) rcnt++;
        else break;
    }
    cout<<min(n, lcnt+rcnt)<<endl;
return 0;
}
