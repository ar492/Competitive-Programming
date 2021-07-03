#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, cnt, ans;
vector<array<int, 2>> items; // <required, threshold>

bool cmp(array<int, 2> a, array<int, 2> b){
	if(a[1]==b[1]) return a[0]<b[0];
	return a[1]<b[1];
}

signed main(){
	cin>>n;
	items.resize(n);
	for(int i=0; i<n; i++) cin>>items[i][0]>>items[i][1];
	int l=0, r=n-1;
	sort(items.begin(), items.end(), cmp);
	while(l<=r){
		int rmv=min(items[r][0], items[l][1]-cnt);
		if(items[r][0]-rmv==0) r--;
		cnt+=rmv; ans+=rmv*2;
		while(l<=r && cnt>=items[l][1]){
			cnt+=items[l][0];
			ans+=items[l][0];
			l++;
		}
	}
	cout<<ans<<endl;
}
