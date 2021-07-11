#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
ifstream fin("input.in");

int main(){
int t; fin>>t;
for (int w=0; w<t; w++){
    string b;
    fin>>b;
    string a="";
    a+=b[0];
    for(int i=1; i<b.length()-1; i+=2){
        a+=b[i];
    }
    a+=b[b.length()-1];
    cout<<a<<endl;
}

return 0;
}
