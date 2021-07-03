#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

struct point{
int x; int y;
};

double distfind(point a, point b){
    return (sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)));
}
double heron(double s1, double s2, double s3){
    double semi=0.5*(s1+s2+s3);
    return(sqrt(semi*(semi-s1)*(semi-s2)*(semi-s3)));
}
bool validpoints(point a, point b, point c){
if((a.x==b.x && a.y==c.y)||(a.x==b.x && b.y==c.y)||(b.x==c.x && b.y==a.y)||(b.x==c.x && c.y==a.y)||(a.x==c.x && c.y==b.y)||(a.x==c.x && a.y==b.y))
    return true;
else
    return false;
}
int main(){
ifstream cin("triangles.in");
ofstream cout("triangles.out");
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n; cin>>n;
vector<point> points;
for(int i=0; i<n; i++){
    point p;
    int tempx, tempy; cin>>tempx>>tempy;
    p.x=tempx; p.y=tempy;
    points.pb(p);
}
double maxarea=0;
for(int i=0; i<points.size(); i++){
    for(int j=i+1; j<points.size(); j++){
        for(int k=j+1; k<points.size(); k++){
            if(validpoints(points[i], points[j], points[k])){
                double area=heron(distfind(points[i], points[j]), distfind(points[j], points[k]), distfind(points[i], points[k]));
                maxarea=max(maxarea, area);
            }
        }
    }
}
cout<<(int)(maxarea*2.0)<<"\n";
return 0;
}
