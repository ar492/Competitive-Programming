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

struct pail{
    int A;
    int B;
    int t;
};

int v[101][101];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("pails.in"); ofstream cout("pails.out");
    int mn=INF;
    int x,y,k,m;
    cin>>x>>y>>k>>m;
    if(y>x) swap(x,y); //x geq y
    queue<pail> q;
    q.push({0,0,1});
    v[0][0]=true;
    while (!q.empty()){
       pail p = q.front();
       q.pop();
       int a=p.A; int b=p.B; int tn=p.t;
       mn=min(mn, abs(m-(a+b)));
       if(tn<=k){
           if(!v[0][b]){v[0][b]=1; q.push({0,b,tn+1});}//empty bucket x
           if(!v[a][0]){v[a][0]=1; q.push({a,0,tn+1});}//empty bucket y
           if(!v[x][b]){v[x][b]=1; q.push({x,b,tn+1});}//fill bucket x
           if(!v[a][y]){v[a][y]=1; q.push({a,y,tn+1});}//fill bucket y
           int xfill=a+b; int yfill=0;
           if(a+b>x){yfill=b-(x-a); xfill=x;}
           if(!v[xfill][yfill]){v[xfill][yfill]=1; q.push({xfill, yfill, tn+1});} //pour y to x
           int xf=0; int yf=a+b;
           if(a+b>y){xf=a-(y-b); yf=y;}
           if(!v[xf][yf]){v[xf][yf]=1; q.push({xf,yf,tn+1});}//pour x to y
        }
    }
    cout<<mn<<endl;

return 0;
}
