#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
int t=0;
cin>>t;
for(int k=0;k<t;k++){
    string s; cin>>s;
    int ones=0; int zeroes=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')
            ones++;
        else
            zeroes++;
    }
    if(min(ones,zeroes)%2==1){cout<<"DA"<<endl;}
    else{cout<<"NET"<<endl;}
    ///1010100
    ///10100
    ///100
    ///0

    ///11110000
    ///111000
    ///1100
    ///10
    /// null

    ///111110
}
return 0;
}
