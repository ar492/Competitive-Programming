#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

struct log{
    int p; int h;
};
bool cmp(log a, log b){
    return a.p<b.p;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        cout<<"Case #"<<q+1<<": ";
        int n; cin>>n;
        vector<log> logs(n);
        for(int i=0; i<n; i++)
            cin>>logs[i].p>>logs[i].h;
        sort(logs.begin(), logs.end(), cmp);

    }
return 0;
}
