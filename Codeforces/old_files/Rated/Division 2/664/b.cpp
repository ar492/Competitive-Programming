#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;

int n,m,x,y; bool chk=true;
//0 is left, 1 is right, 2 is up, 3 is down

void left(){
    //cout<<"left"<<endl;
    for(int i=1; i<y; i++){
        if(chk){
            for(int j=n; j>=1; j--){
                cout<<j<<" "<<i<<endl;
            }
        }
        else{
            for(int j=1; j<=n; j++){
                cout<<j<<" "<<i<<endl;
            }
        }
        chk=!chk;
    }
}
void right(){
   // cout<<"right"<<endl;
    for(int i=y+1; i<=m; i++){
        if(chk){
            for(int j=n; j>=1; j--){
                cout<<j<<" "<<i<<endl;
            }
        }
        else{
            for(int j=1; j<=n; j++){
                cout<<j<<" "<<i<<endl;
            }
        }
        chk=!chk;
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>x>>y;
    cout<<x<<" "<<y<<endl;
    for(int i=1; i<=n; i++){
        if(i!=x)
            cout<<i<<" "<<y<<endl;
    }
    left();
    right();

return 0;
}
