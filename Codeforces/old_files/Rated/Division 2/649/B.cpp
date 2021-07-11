#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
ifstream fin("input.in");
int main(){
int t; fin>>t;
for (int w=0; w<t; w++){
    int n; fin>>n;
    vector<int> p;
    for (int i=0; i<n; i++){
        int temp; fin>>temp; p.pb(temp);
    }
    for (int i=2; i<p.size(); i++){
        cout<<"i is "<<i<<endl;
        if(p.size()>2){
        if(p[i-2]<p[i-1] && p[i-1]<p[i]){cout<<"erasing "<<p[i-1]<<" and i-=1 "<<endl;p.erase(p.begin()+i-1);i-=1;}
        else if(p[i-2]>p[i-1] && p[i-1]>p[i]){cout<<"erasing "<<p[i-1]<<" and i-=1 "<<endl;p.erase(p.begin()+i-1);i-=1;}
        }
    }
    cout<<p.size()<<endl;
    for (int i=0; i<p.size(); i++){
        cout<<p[i]<<" ";
    }cout<<endl;
}///should be
///2
///5 1
return 0;
}
