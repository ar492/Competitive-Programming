#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)((X).size())
#define len(X) (int)((X).length())

string s;
int n, m;
vector<int> p[6];

void calc(char x, char y, vector<int> &v){
	int cnt=0;
	string str=string()+x+y;

	cnt+=(x!=s[0]);
	v.push_back(cnt);
	cnt+=(y!=s[1]);
	v.push_back(cnt);

	for(int i=2; i<n; i++){
		for(char c:{'a', 'b', 'c'}){
			if(c!=str[i-1] && c!=str[i-2]){
				v.push_back(cnt+=(c!=s[i]));
				str.push_back(c);
			}
		}
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	cin>>n>>m>>s;
	
	int cnt=0;
	if(n>2)
		for(char i:{'a', 'b', 'c'})
			for(char j:{'a', 'b', 'c'})
				if(i!=j)
					calc(i, j, p[cnt++]);
	while(m--){
		int l, r; cin>>l>>r;
		l--; r--;
		if(n==1) cout<<0<<endl;
		else if(n==2) cout<<(s[0]==s[1])<<endl;
		if(n<=2) continue;
		int ans=1e9;
		for(int i=0; i<6; i++)
			ans=min(ans, p[i][r]-(l ? p[i][l-1] : 0));
		cout<<ans<<endl;
	}	
}

