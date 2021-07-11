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

}
res = 0
for init = 0 to inf
    cur = init
    ok = true
    for i = 1 to |s|
        res = res + 1
        if s[i] == '+'
            cur = cur + 1
        else
            cur = cur - 1
        if cur < 0
            ok = false
            break
    if ok
        break
return 0;
}
