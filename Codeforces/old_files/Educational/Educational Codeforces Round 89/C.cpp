#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
ifstream fin("input.txt");
struct point{
int x, y, value;
};
int main(){
int t=0;
fin>>t;
for(int i=0; i<t; i++){
    int n, m;
    fin>>n>>m;
    vector<point> sum[n+m-1];
    for(int j=0; j<n; j++){
        for(int k=0; k<m; k++){
            bool temp; fin>>temp;
           /// cout<<"j, k is "<<j<<" "<<k<<endl;
            point p; p.x=j; p.y=k; p.value=temp;
            ///cout<<"sum["<<j+k<<".push_back("<<p.x<<","<<p.y<<endl;
            sum[j+k].push_back(p);
        }
    }
/*
    for(int j=0; j<n+m-1; j++){
        cout<<"For sum["<<j<<"]: "<<endl;
        for(int k=0; k<sum[j].size(); k++){
            cout<<"     ("<<sum[j][k].x<<","<<sum[j][k].y<<")"<<endl;
        }
    }
*/
    int accum=0;
        for(int j=0; j<(n+m-1)/2; j++){
       /// cout<<"For sum["<<j<<"]: "<<endl;
        int onecounter=0;
        int zerocounter=0;
        for(int k=0; k<sum[j].size(); k++){
    ///   cout<<"sum["<<j<<"]["<<k<<"].value("<<sum[j][k].value<<") !=sum["<<(n+m-2)-j<<"]["<<k<<"].value ("<<sum[(n+m-2)-j][k].value<<")"<<endl;
        if (sum[j][k].value+sum[(n+m-2)-j][k].value==0){zerocounter+=2;}
        else if(sum[j][k].value+sum[(n+m-2)-j][k].value==1){onecounter++; zerocounter++;}
        else if (sum[j][k].value+sum[(n+m-2)-j][k].value==2){onecounter+=2;}
                ///(n+m-2)-j and the current one
     ///     cout<<"     ("<<sum[j][k].x<<","<<sum[j][k].y<<")"<<endl;
        }
        if(onecounter>=zerocounter){accum+=zerocounter;}
        else if (onecounter<zerocounter){accum+=onecounter;}
    }
cout<<accum<<endl;
}

return 0;
}
