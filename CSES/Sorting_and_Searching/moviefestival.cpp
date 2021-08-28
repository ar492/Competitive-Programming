#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

struct interval{
    int f; int s;
};
bool cmp(interval a, interval b){
    return ((int)a.s<(int)b.s);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<interval> iv(n);
    for(int i=0; i<n; i++)
        cin>>iv[i].f>>iv[i].s;
    sort(iv.begin(), iv.end(), cmp);

    int cnt=0;
    int prev=0;
    for(int i=0; i<n; i++){
        if(iv[i].f >= prev)
            {prev=iv[i].s; cnt++;}
    }
    cout<<cnt<<endl;
return 0;
}
