#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first
#define y second
const ll MOD=(ll)1e9+7, sz=2e4+1;

vector<pair<ll,ll>> xs[sz], ys[sz]; //array of vec of pairs
//xs is horizontal lines, ys is vertical lines
pair<int, int> input[(ll)1e5];

map<pair<int, int>, ll> xans, yans;
int n;
void xsum(){
    for(int i=0; i<sz; i++){
        if(!xs[i].empty()){
            ll s0=0;
            vector<pair<ll, ll>> line=xs[i];

            int ls=line.size();
            for(int j=1; j<ls; j++)
                s0+=line[j].x-line[0].x;

            xans[{line[0].x, line[0].y}]=s0;
            for(int j=0; j<ls-1; j++)
                xans[{line[j+1].x, line[j+1].y}]=xans[{line[j].x, line[j].y}]+(line[j+1].x-line[j].x)*(2*j-ls+2);
        }
    }
}

void ysum(){
    for(ll i=0; i<sz; i++){
        if(!ys[i].empty()){
            ll s0=0;
            vector<pair<ll, ll>> line=ys[i];
            int ls=line.size();
            for(int j=1; j<ys[i].size(); j++)
                s0+=line[j].y-line[0].y;

            yans[{line[0].x, line[0].y}]=s0;
            for(int j=0; j<ls-1; j++)
                yans[{line[j+1].x, line[j+1].y}]=yans[{line[j].x, line[j].y}]+(line[j+1].y-line[j].y)*(2*j-ls+2);
        }
    }
}
int main(){
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    cin>>n;
    for(ll i=0; i<n; i++){
        ll x,y; cin>>x>>y;
        x+=10000, y+=10000;
        input[i]={x, y};
        xs[y].push_back({x, y}); //lie on same horiz line
        ys[x].push_back({x, y}); //lie on same vert line
    }
    for(ll i=0; i<sz; i++){
        sort(xs[i].begin(), xs[i].end());
        sort(ys[i].begin(), ys[i].end());
    }
    xsum(); ysum();
    ll areaSum=0;
    for(ll i=0; i<n; i++){
        areaSum+=(xans[{input[i].x, input[i].y}]*yans[{input[i].x, input[i].y}])%MOD;
        areaSum%=MOD;
    }
    cout<<areaSum<<endl;
return 0;
}
