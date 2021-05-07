/*
Solution:
keep a prefix sum
when you update a range [l, r] by k
x[l]+=k, x[r+1]-=k (this is the original array, not a prefix sum)
then, MAKE/QUERY a prefix sum in logn time using BIT (sum from l to r)
idea is essentially same as difference array, but with BIT
to make it online (form prefix in logn instead of n)
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int sz=2e5+1;
int n, q, x[sz], bit[sz], bitD[sz];

void update(int i, int v){
        if(i>n) return;
        cout<<"called for "<<i<<" "<<v<<endl;
        for(; i<=n; i+=(i&-i)){cout<<"at index "<<i<<endl;  bit[i]+=v; }
}
void updateD(int i, int v){
        if(i>n) return;
        for(; i<=n; i+=(i&-i)) bitD[i]+=v;
}

int sum(int i){ // sum from 1 to i inclusive
        int s=0;
        for(; i>0; i-=(i&-i)) s+=bit[i];
        return s;
}
int sumD(int i){
        int s=0;
        for(; i>0; i-=(i&-i)) s+=bitD[i];
        return s;
}

signed main(){

        cin>>n>>q;
        for(int i=0; i<n; i++){
                cin>>x[i];
                update(i+1, x[i]); // bit is 1-indexed always
        }
        cout<<"BIT: ";
        for(int i=1; i<=n; i++) cout<<bit[i]<<" "; cout<<endl;
        while(q--){
                int type; cin>>type;
                if(type==1){ // update
                        int a,b,u; cin>>a>>b>>u; // increase [a,b] by u
                        updateD(a, u);
                        updateD(b+1, -u);
                      //  cout<<"BIT: ";
                      //  for(int i=1; i<=n; i++) cout<<bit[i]<<" "; cout<<endl;
                }
                else{
                        int k; cin>>k;
                        cout<<"what is value at pos "<<k<<endl;
                        cout<<sum(k)-sum(k-1)+sumD(k)<<endl;
                }
        }
        return 0;
}


/*

8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4

*/
