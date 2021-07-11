#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n,x; cin>>n>>x;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        sort(a.begin(), a.end());
        int m=a[a.size()-1]; int nt=0; int sz=1;
        while(a.size()!=0){
            m=min(m, a[a.size()-1]);
            if(a[a.size()-1]*sz>=x){
                nt++; a.pop_back(); sz=1;
            }
            else{
                a.pop_back(); sz++;
            }
        }
        cout<<nt<<endl;
    }
return 0;
}
