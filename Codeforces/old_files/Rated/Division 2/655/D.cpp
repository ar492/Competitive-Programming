#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

struct num{
    ll val; ll index;
};
bool cmp(num a, num b){
    return(a.val>b.val);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int n; cin>>n;
        vector<num> a(n);
        for(int i=0; i<n; i++){
            int temp; cin>>temp;
            a[i].val=temp; a[i].index=i+1;
        }
        sort(a.begin(), a.end(), cmp);
        if(n==1)
            cout<<a[0].val<<endl;
        else if (n==3){
            cout<<a[0].val+a[1].val<<endl;
        }
        else{
            if(abs(a[0].index-a[1].index)!=1 && abs(a[0].index-a[1].index)!=(n-1) && abs(a[1].index-a[2].index)!=1 && abs(a[1].index-a[2].index)!=-1){
                cout<<a[0].val+a[1].val+a[2].val<<endl;
            }
            else{
                cout<<a[0].val+a[1].val+a[3].val<<endl;
               // cout<<a[0].index<<" "<<a[1].index<<" "<<a[3].index<<endl;
            }
        }

return 0;
}


