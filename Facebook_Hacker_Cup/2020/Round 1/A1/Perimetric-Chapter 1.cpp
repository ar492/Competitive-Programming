#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef long long ll;
using namespace std;

struct room{
    int L; int H;
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    int N,K,W; cin>>N>>K>>W;//N rooms, input till K, width of rectangles
    room rooms[N];
    for(int casenum=1; casenum<=t; casenum++){
        cout<<"Case #"<<casenum<<endl;
        for(int i=0; i<K; i++) cin>>rooms[i].L
        int al,bl,cl,dl; cin>>al>>bl>>cl>>dl;
        for(int i=0; i<K; i++) cin>>rooms[i].H;
    }
return 0;
}
