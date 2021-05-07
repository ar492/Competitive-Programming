#include<bits/stdc++.h>
using namespace std;

const int dr[4]={1, -1, 0, 0};
const int dc[4]={0, 0, 1, -1};
char dir[4]={'D', 'U', 'R', 'L'};
int opposite[4]={1, 0, 3, 2};
bool vis[1000][1000];
char g[1000][1000];
int prevstep[1000][1000];
pair<int, int> start, finish;
int n,m;

int main(){

	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>g[i][j];
			if(g[i][j]=='A') start={i, j};
			if(g[i][j]=='B') finish={i, j};
		}
	}
	vis[start.first][start.second]=true;
	queue<pair<int, int>> q;
	q.push(start);
	while(!q.empty()){
		int r=q.front().first, c=q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int rr=r+dr[i], cc=c+dc[i];
            if(rr<0 || cc<0 || rr>=n || cc>=m) continue;
            if(vis[rr][cc] || g[rr][cc]=='#') continue;
            vis[rr][cc]=true;
            prevstep[rr][cc]=opposite[i]+1;
            q.push({rr, cc});
            if(g[rr][cc]=='B'){ q = queue<pair<int, int>>(); break; }
		}
	}

	if(prevstep[finish.first][finish.second]==0){
		cout<<"NO"<<endl; return 0;
	}

	else{
		int r=finish.first, c=finish.second;
		string ans;
		int cnt=0;
		while(g[r][c]!='A'){
			int ps=prevstep[r][c]-1;
			ans+=dir[opposite[ps]];
			r+=dr[ps], c+=dc[ps];
			cnt++;
			if(cnt>=(int)1e6+1){ cout<<":("<<endl; break;}
		}
		reverse(ans.begin(), ans.end());
		cout<<"YES\n"<<ans.length()<<"\n"<<ans<<"\n";
		return 0;
	}
}


