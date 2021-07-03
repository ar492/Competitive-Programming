#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

void setIO(string name) {
        cin.tie(0)->sync_with_stdio(0);
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
}

signed main(){
       setIO("lightsout");
	int n; cin>>n;
	vector<pair<int, int>> pts;
	for(int i=0; i<n; i++){
              int x,y; cin>>x>>y; pts.push_back({x, y});
	}
	int sum=0;
	for(int i=2; i<n; i++){
              if(pts[i].x==pts[i-1].x){
                     sum+=abs(pts[i].y-pts[i-1].y);
              }
              else sum+=abs(pts[i].x-pts[i-1].x);
              if(i==n-1){
                     if(pts[i].x==pts[0].x) sum+=abs(pts[i].y-pts[0].y);
                     else sum+=abs(pts[i].x-pts[0].x);
              }
	}
	//cout<<"sum = "<<sum<<endl;
	int start;
       if(pts[1].x==pts[0].x) start=abs(pts[1].y-pts[0].y);
       else start=abs(pts[1].x-pts[0].x);

       cout<<sum-start<<endl;


}

// actually read tips.txt
