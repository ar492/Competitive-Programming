#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
ifstream fin("input.in");

int main(){
int t; fin>>t;
for (int w=0; w<t; w++){
    int n, k; fin>>n>>k;
    string s; fin>>s;
   /// cout<<"s is "<<s<<endl;
    int counter=0;
    ///2*k+1 consecutive 0's
    int consec=2*k+1;
    ///for(int i=0; i<)
    if(s[0]=='0'){
        bool check=true;
        for (int i=0; i<=k; i++){
            if(s[i]=='1'){check=false;}
        }
        if(check==true && s[0]=='0'){
          ///  cout<<"c1"<<endl;
                s[0]='1';counter++;}
    }
    for(int i=0; i<s.length(); i++){
        bool check=false;
      /// cout<<"i,consec"<<i<<" "<<consec<<endl;
        for(int j=0; j<=consec; j++){
            if(i+j<s.length()){
            if(s[i+j]=='1'){check=true;}
            }
        }
        if(check==false && s[consec/2+1]=='0'){
               ///  cout<<"c2"<<endl;
        counter++; s[consec/2+1]='1';}
    }
    bool check=false;
    if(k!=s.length()){
      //  cout<<"s.length()-k-1 is "<<(s.length()-k)-1<<endl;
    //cout<<"s.length() is "<<s.length()<<endl;
    //cout<<"k is "<<k<<endl;
    for(int i=(s.length()-k)-1; i<s.length(); i++){
        if(s[i]=='1'){check=true;}
    }
    if(check==false && s[s.length()-1]=='0'){
            // cout<<"c3"<<endl;
    s[s.length()-1]='1';counter++;}
    }
   /// cout<<"at end, s is "<<s<<endl;
    cout<<counter<<endl;
}


return 0;
}
