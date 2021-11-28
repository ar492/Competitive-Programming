
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
const int sz=505;
char g[sz][sz];
int ans[sz][sz];
bool possible=1;
set<array<int, 2>> marked;
int dr[]={1, -1, 0, 0};
int dc[]={0, 0, 1, -1};

void ff(int r, int c){
	int sum=0;
	for(int i=0; i<4; i++){
		int rr=r+dr[i];
		int cc=c+dc[i];
		if(!(rr && cc && rr<n && cc<m)) continue;
		if(g[rr][cc]=='X') continue;
		sum+=ans[rr][cc];
	}
	//if(
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>g[i][j];
			marked.insert({i, j});
		}
	}
	if(possible) cout<<"YES"<<endl;
	else{
		cout<<"NO"<<endl; return 0;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<c; j++){
			cout<<ans[i][j]<<" ";
		}cout<<endl;
	}

}
