#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

struct vals{
    int val; int index;
};
bool cmp(vals A, vals B){
    return A.val<B.val;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vals a[n];
        for(int i=0; i<n; i++){
            vals tempv;
            tempv.index=i+1;
            cin>>tempv.val;
            a[i]=tempv;
        }
        sort(a, a+n, cmp);
        if(a[0].val+a[1].val<=a[n-1].val){
            cout<<a[0].index<<" "<<a[1].index<<" "<<a[n-1].index<<endl;
        }
        else cout<<-1<<endl;
    }
return 0;
}
