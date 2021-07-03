#include <bits/stdc++.h>
using namespace std;

int n; char grid[20][20]; bool visited[20][20];

struct pcl{
    int r1, r2, c1, c2;
    bool operator < (const pcl &other) const { return r1 < other.r1; }

};
vector<pcl> allpcls;

void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("where.in","r",stdin);
    freopen("where.out","w",stdout);
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>grid[i][j];
    }
}

void reset(){ for(int i=0; i<20; i++) for(int j=0; j<20; j++) visited[i][j]=0; }

int dx[4]={0, 1, 0, -1}; int dy[4]={1, 0, -1, 0};

void ff(int r, int c, char color, int r1, int r2, int c1, int c2){
    visited[r][c]=1;
    for(int i=0; i<4; i++){
        int rr=r+dx[i];
        int cc=c+dy[i];
        if(rr>=r1 && rr<=r2 && cc>=c1 && cc<=c2 && grid[rr][cc]==color && !visited[rr][cc])
            ff(rr,cc, color, r1, r2, c1, c2);
    }
}

bool PCL_in_PCL(int x, int y)
{
  return allpcls[x].r1 >= allpcls[y].r1
    && allpcls[x].r2 <= allpcls[y].r2
    && allpcls[x].c1 >= allpcls[y].c1
    && allpcls[x].c2 <= allpcls[y].c2;
}

bool PCL_maximal(int x)
{
  for (int i=0; i<allpcls.size(); i++)
    if (i!=x && PCL_in_PCL(x,i)) return false;
  return true;
}


int main(){
   // n=20;
   setup();
    int cnt=0;

    for(int c1=0; c1<n; c1++){
        for(int c2=c1; c2<n; c2++){ //columns
            for(int r1=0; r1<n; r1++){
                for(int r2=r1; r2<n; r2++){
                    map<char, int> pcls; //<color, # ff's>
                    for(int r=r1; r<=r2; r++){
                        for(int c=c1; c<=c2; c++){
                            if(!visited[r][c]){
                               ff(r, c, grid[r][c], r1, r2, c1, c2);
                               pcls[grid[r][c]]++;
                            }
                        }
                    }
                    if(pcls.size()==2 && ((pcls.begin()->second==1 && (++pcls.begin())->second>1) ||  (pcls.begin()->second>1 && (++pcls.begin())->second==1))){
                      //  cnt++;
                      //  cout<<"for cols: "<<c1<<" : "<<c2<<" and rows "<<r1<<" : "<<r2<<" is PCL"<<endl;
                       // bool insertit=1;
                       // set<pcl> toerase;
                       // for(set<pcl>::iterator it=allpcls.begin(); it!=allpcls.end(); it++){
                        //    if(((*it).r1<=r1&&(*it).r2>=r2&&(*it).c1<=c1&&(*it).c2>=c2)){ insertit=0; break; }
                         //   else if((r1<=(*it).r1&&r2>=(*it).r2&&c1<=(*it).c1&&c2>=(*it).c2)){ toerase.insert(*it); }
                       // }
                        //for(auto i:toerase) allpcls.erase(i);
                        //if(insertit)
                            allpcls.push_back({r1, r2, c1, c2});
                    }
                    reset();
     //               cnt++;
                }
            }
        }
    }
    for(int i=0; i<allpcls.size(); i++){
        if(PCL_maximal(i)) cnt++;
    }
    cout<<cnt<<endl;

return 0;
}
