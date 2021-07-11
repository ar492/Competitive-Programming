#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            int temp; cin>>temp; a[i]=temp;
        }
        int ge0=0; int leq0=0;
        for(int i=0; i<n-1; i++){
            if(a[i+1]-a[i]=0;){
                leq0++; ge0++;
            }
            else if (a[i+1]-a[i]<0)
                leq0++;
            else if (a[i+1]-a[i]>0)
                ge0++;
        }
        if(ge0>=(n-1)/2 && leq0>=(n-1)/2){
            for(int i=0; i<n-1; i++){
                cout<<a[i]<<" ";
            }cout<<endl;
        }

    }

    return 0;
}
