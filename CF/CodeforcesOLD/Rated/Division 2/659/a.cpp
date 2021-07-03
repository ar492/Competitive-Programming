#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

char next(char c){
    return((char)((int)((c+1)-97)%26+97));
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n; cin>>n; int a[n];
        int m=0;
        for(int i=0; i<n; i++)
            cin>>a[i];
        string s="a";
        for(int i=1; i<51; i++)
            s+=next(s[i-1]);
        cout<<s<<endl;
        string cur=s;

        for(int i=0; i<n; i++){
            cur[a[i]]=next(cur[a[i]]);
            cout<<cur<<endl;
        }
    }
return 0;
}
