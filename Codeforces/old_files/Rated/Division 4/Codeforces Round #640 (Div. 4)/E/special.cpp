#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    for(int qq=0; qq<t; qq++){
        int n; cin>>n; int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        vector<int> c(n+1, 0);
        for(int i:a)
            c[i]++;

        int p[n]; p[0]=a[0];
        for(int i=1; i<n; i++)
            p[i]=p[i-1]+a[i];
        //for(int i=0; i<n; i++){
        //    cout<<p[i]<<" ";
        //}cout<<endl;
        int cnt=0;
        if(n>1 && p[1]<=n){
            cnt+=c[p[1]]; c[p[1]]=0;
        }
       // cout<<cnt<<endl;
        for(int i=0; i<n; i++){
            for(int j=i+2; j<n; j++){
                //cout<<"i j: "<<i<<" "<<j<<endl;
                if(p[j]-p[i]<=n){
                    //cout<<cnt<<"+= c["<<p[j]<<"-"<<p[i]<<"] ("<<c[p[j]-p[i]]<<")"<<endl;
                    cnt+=c[p[j]-p[i]];
                    c[p[j]-p[i]]=0;
                }
                if(p[j]<=n){
                    cnt+=c[p[j]];
                    c[p[j]]=0;
                }
            }
        }
        cout<<cnt<<endl;
    }
return 0;
}
