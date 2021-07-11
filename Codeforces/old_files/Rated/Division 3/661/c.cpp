#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int n;
int test(int s, int w[]){
    int cnt=0; vector<bool> v(n, 0);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(w[i]+w[j]==s && v[i]==0 && v[j]==0){
                v[i]=1; v[j]=1;
                cnt++;
            }
        }
    }
    return cnt;
}
void exe(){
    cin>>n;
    int w[n];
    for(int i=0; i<n; i++)
        cin>>w[i];
    int m=0;
    for(int i=1; i<=100; i++)
        m=max(m, test(i, w));
    cout<<m<<endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int qq=0; qq<t; qq++){
        exe();
    }
return 0;
}
