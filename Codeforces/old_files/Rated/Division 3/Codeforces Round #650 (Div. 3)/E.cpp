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
    int letterCount[26];
    for(int i=0; i<26; i++){letterCount[i]=0;}
    ///repeating subsequence of length (divisor of k)
    int m1=0;
    for(int i=n; i>0; i--){
        cout<<"k is "<<k<<", and i is "<<i<<endl;
        if(k%i==0){m1=i; break;}
    }
    ///if(n<k){cout<<m1<<endl;}
    cout<<m1<<endl;
}

return 0;
}
