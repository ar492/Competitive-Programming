#include<bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define sz(X) ((int)(X.size()))
#define len(X) ((int)(X.length()))
#define eb emplace_back
#define pb push_back
#define int long long
#define nl "\n"
using namespace std;

int totalSteps(vector<int>& nums){
	vector<int> sources;
	int n=(int)nums.size();
	for(int i=0; i<n-1; i++){
		if(nums[i+1]<nums[i]){
			sources.emplace_back(i);
		}
	}
	vector<int> ptr(n);
	for(int i=0; i<n; i++){
		ptr[i]=i+1;
	}
	int ans=0;
	while(true){
		bool chk=0;
		for(auto it=sources.rbegin(); it!=sources.rend(); it++){
			int i=*it;
			if(ptr[i]!=n and nums[i]>nums[ptr[i]]){
				ptr[i]=ptr[ptr[i]];
				chk=1;
			}
		}
		if(!chk) break;
		ans++;
	}
	return ans;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0); cin.exceptions(ios_base::failbit);
	vector<int> v = { 5,3,4,4,7,3,6,11,8,5,11 };
	cout<<totalSteps(v)<<endl;

}
