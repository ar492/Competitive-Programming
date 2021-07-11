#include <bits/stdc++.h>
using namespace std;

void exe(int ocnt, int ecnt, int x){
    for(int o=ocnt; o>=0; o--){
        if(o%2==1 && ((x%2==0 && o<x) || (x%2==1 && o<=x)) && ecnt>=x-o){
            cout<<"Yes"<<endl; return;
        }
    }
    cout<<"No"<<endl;
    return;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        int ocnt=0, ecnt=0;
        for(int i=0; i<n; i++){
            int u; cin>>u;
            (u%2==0) ? ecnt++ : ocnt++;
        }
        //try all parities (ocnt odd ecnt even, ocnt-1 odd, ecnt+1 even... )
        exe(ocnt, ecnt, x);


    }
return 0;
}
