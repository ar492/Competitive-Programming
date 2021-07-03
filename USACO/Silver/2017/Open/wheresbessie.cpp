#include <bits/stdc++.h>
#define ss second
using namespace std;

struct PCL{
    int i; int j; int k; int l;
    bool operator<(PCL other) const{    return i > other.i;     }
};
char g[20][20];
char gc[20][20];
map<char, int> m; //char, how many times ff was called for it
set<PCL> pcls; //check the valid pcls each time we add a new valid one to avoid overcounting

void reset(){
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){    gc[i][j]=g[i][j];   }
    }
    m.clear();
}
int dx[4]={0, 1, 0, -1}; int dy[4]={1, 0, -1, 0};

void ff(int x, int y, PCL box, char color){
    gc[x][y]='0';
    for(int q=0; q<4; q++){
        int xx=x+dx[q];
        int yy=y+dy[q];
        if(xx>=box.i && xx<=box.k && yy>=box.j && yy<=box.l && gc[xx][yy]==color){
            //if(box.i==0 && box.k==3 && box.j==0 && box.l==2) cout<<"going to "<<xx<<" "<<yy<<endl;
            ff(xx, yy, box, color);
        }
    }
}
void printpcls(){
    for(PCL x:pcls) cout<<x.i<<" "<<x.j<<" "<<x.k<<" "<<x.l<<endl;
}
//void print(PCL x) // print pcl
//{
 //   cout<<"deleting this one: ["<<x.i<<"]["<<x.j<<"]->["<<x.k<<"]["<<x.k<<"]"<<endl;
//}
//void print2(PCL x) // print pcl
//{
 //   cout<<"["<<x.i<<"]["<<x.j<<"]->["<<x.k<<"]["<<x.k<<"]"<<endl;
//}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("where.in","r",stdin);
    //freopen("where.out","w",stdout);
    int n; cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin>>g[i][j];
    int cnt=0;
    reset();
    vector<PCL> deletions;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){// from [i][j]
            for(int k=i; k<n; k++){
                for(int l=j; l<n; l++){// to [k][l]
  //                  cout<<"called for ["<<i<<"->"<<k<<"]["<<j<<"->"<<l<<"]"<<endl;
                    for(int rindex=i; rindex<=k; rindex++){
                        for(int cindex=j; cindex<=l; cindex++){
                            if(gc[rindex][cindex]!='0'){
 //                               if(i==0 && k==3 && j==0 && l==2){ cout<<"ff["<<rindex<<"]["<<cindex<<"]"<<endl;}
                                ff(rindex, cindex, {i, j, k, l}, g[rindex][cindex]);
                                m[g[rindex][cindex]]++;
                            }
                        }
                    }
                    //if(i==0 && k==3 && j==0 && l==2){
                     //   cout<<"m.size() = "<<m.size()<<endl;
                     //   cout<<"map: "<<endl;
                     //   for(auto x:m){ cout<<x.first<<"->"<<x.second<<endl; }
                  //      cout<<"m[0]
                   // }
                    vector<int> v;
                    for(auto x:m){ v.push_back(x.second); }
                    if(v.size()==2 && ((v[0]==1 && v[1]>1) || (v[0]>1 && v[1]==1))){
   //                     cout<<"success for "<<i<<" "<<j<<" -> "<<k<<" "<<l<<endl;
     //                   cout<<"map: "<<endl;
       //                 for(auto x:m){ cout<<x.first<<"->"<<x.second<<endl; }
                        bool valid=1;

                        for(PCL itr:pcls){
                            print2(itr);
                            if(itr.i<=i && itr.j<=j && itr.k>=k && itr.l>=l) valid=0;
                            else if(i<=itr.i && j<=itr.j && k>=itr.k && l>=itr.l) {cout<<"cnt :"<<cnt<<"->"<<cnt-1<<endl; print(itr); cnt--; deletions.push_back(itr);}
                        }
                        for(PCL itr:deletions) pcls.erase(itr);
                        if(valid){ cout<<"THIS IS ACTUALLY VALID, cnt is "<<cnt+1<<endl; printpcls(); pcls.insert({i, j, k, l}); cnt++; }
                    }
                    reset();
                }
            }
        } cout<<endl;
    }
    cout<<cnt<<endl;
return 0;
}
