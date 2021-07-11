#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
int t;cin>>t;
for(int q=0;q<t;q++){
    int n; string s; cin>>n>>s;
    bool check=false;
    for(int i=1;i<s.length();i++){
        if(s[i-1]>s[i]){check=true; break;}
    }
    if(check==true){
        int i=0;
        while(s[i]=='0')
            i++;
        int j=s.length()-1;
        while(s[j]=='1')
            j--;
        j=s.length()-1-j;
        for(int k=0;k<=i;k++)
            cout<<"0";
        for(int k=0;k<j;k++)
            cout<<"1";
        cout<<endl;
    }
    else{cout<<s<<endl;}
}
return 0;
}
