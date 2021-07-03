#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
int main(){
int t; cin>>t;
for(int j=0;j<t;j++){
    for(int i=0;i<9;i++){
        string temp; cin>>temp;
        for(int k=0;k<9;k++){if(temp[k]=='1'){cout<<'2';}else{cout<<temp[k];}}
        cout<<endl;
    }
}
return 0;
}
