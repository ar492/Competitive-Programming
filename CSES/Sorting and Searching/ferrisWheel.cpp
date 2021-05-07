#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

vector<int> p;
vector<bool> v;
int n,x,cnt;

bool change(){
    int r=n-1; int l=0;
    bool c=0;
    while(l<r && l>=0){
        //cout<<"l,r : "<<l<<" "<<r<<endl;
        if(v[r] || v[l]){
            if(v[r])
                r--;
            if(v[l])
                l++;
        }
        else if(!v[l] && !v[r]){
            if(p[l]+p[r]>x)
                r--;
            else if (p[l]+p[r]<=x){
                cnt+=1; v[l]=1; v[r]=1; r--; l++; c=1;
            }
        }
       // cout<<"l,r: "<<l<<" "<<r<<endl;
    }
    return c;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>x;
    p.resize(n); v.resize(n);
    for(int i=0; i<n; i++)
        cin>>p[i];
    sort(p.begin(), p.end());
    while(change()){}
    for(int i=0; i<n; i++){
        if(!v[i] && p[i]<=x)
            cnt++;
    }
    cout<<cnt<<endl;
return 0;
}
