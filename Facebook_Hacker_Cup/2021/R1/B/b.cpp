#include<bits/stdc++.h>
using namespace std;

signed main(){
	ifstream cin("traffic_control_input.txt");
	ofstream cout("o.txt");
	int t; cin>>t;
	for(int tc=1; tc<=t; tc++){
		cout<<"Case #"<<tc<<": ";
		int n, m, a, b;
		cin>>n>>m>>a>>b;
		vector<vector<int>> g(n+1, vector<int>(m+1, 1000));
		int cnt=n+m-1;
		if(a<cnt || b<cnt){
			cout<<"Impossible"<<endl;
			continue;
		}
		cout<<"Possible"<<endl;

		g[0][0]=a-(cnt-1);
		g[0][m-1]=b-(cnt-1);
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if((j==0 || j==m-1 || i==n-1) && !(i==0 && (j==0 || j==m-1))) g[i][j]=1;
				cout<<g[i][j]<<" ";
			}cout<<endl;
		}
	}
}
