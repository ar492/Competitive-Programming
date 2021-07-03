/*
#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

bool grid[1000][1000];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("leftout.in");
    ofstream cout("leftout.out");
    int n; cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c; cin>>c;
            grid[i][j]=(c=='L' ? 0 : 1);
        }
    }
    //make all 1
    for(int i=0; i<n; i++){//columns
        if(!grid[0][i]){
            for(int j=0; j<n; j++) grid[j][i]^=1;
        }
    }
    for(int i=0; i<n; i++){//rows
        if(!grid[i][0]){
            for(int j=0; j<n; j++) grid[i][j]^=1;
        }
    }
    pair<int, int> m={1001, 1001};
    int zcnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!grid[i][j]){
                m=min(m, pair<int, int>(i+1, j+1));
                zcnt++;
            }
        }
    }

    if(zcnt==(n-1)*(n-1)){ cout<<"1 1"<<endl; return 0;}
    else if(zcnt==0){ cout<<"-1"<<endl; return 0;}
    else if(zcnt==n-1){ cout<<m.first<<" "<<m.second-1<<endl; return 0;}
    else if(zcnt>1){ cout<<"-1"<<endl; return 0; }
    else cout<<m.first<<" "<<m.second<<endl;
return 0;
}
*/
#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

bool grid[1000][1000];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("leftout.in");
    //ofstream cout("leftout.out");
    int n; cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char c; cin>>c;
            grid[i][j]=(c=='L' ? 1 : 0);
        }
    }
    for(int i=0; i<n; i++){
        if(grid[i][0]==0){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;
            }
        }
    }
    map<string, int> m;
    for(int i=0; i<n; i++){
        string s;
        for(int j=0; j<n; j++){
            s+=(grid[i][j]+'0');
        }
        m[s]++;
    }
    if(m.size()>2 || m.size()==1){ cout<<-1<<endl; return 0;}
    pair<string, int> row={"", -1};
    pair<string, int> crow={"", -1};
    for(auto i:m){
        if(i.second==1) row=i;
        else crow=i;
    }
    if(row.second==-1){ cout<<-1<<endl; return 0; }
    //cout<<row.first<<endl;
    vector<bool> vrow; for(char i:row.first){ vrow.push_back(i-'0'); }
    vector<bool> Crow; for(char i:crow.first){ Crow.push_back(i-'0'); }
   // for(int i=0; i<vrow.size(); i++) cout<<vrow[i]<<" ";cout<<endl;

   for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<grid[i][j]<<" "; cout<<endl;
    }

    for(int i=0; i<n; i++){
        bool match=1;
        for(int j=0; j<n; j++)
            if(vrow[j]!=grid[i][j]){match=0;break;}
        if(match){
            cout<<"match"<<endl;
            for(int j=0; j<n; j++){
                if(Crow[j]!=grid[i][j]){cout<<i+1<<" "<<j+1<<endl; return 0;}
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cout<<grid[i][j]<<" "; cout<<endl;
    }
return 0;
}
