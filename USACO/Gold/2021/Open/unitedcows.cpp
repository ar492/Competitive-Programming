
#include<bits/stdc++.h>
#define int long long
#define left _left
#define right _right
#define all(x) (x).begin(), (x).end()
using namespace std;

const int sz=2e5+5;
int n, c[sz], left, right, cl[sz], cr[sz];; // left = # subarrays such that left occurs more than once, likewise for right
// for each i, what is closest index to the left that has the same value (cl = closest to left, cr = closest to right)
vector<int> oc[sz];
bool done[sz]; // if procedure is done
deque<int> nums;
map<int, int> lr; // left to right mapping

namespace BIT{
       int bit[sz];
       int psum(int x, int sum=0){ for(; x>0; x-=x&-x) sum+=bit[x]; return sum; }
       int sum(int a, int b){ return(psum(b)-psum(a-1)); } // inclusive
       void add(int x, int val){ if(x==0) return; for(; x<sz; x+=x&-x) bit[x]+=val; }
}using namespace BIT;

void procedure(bool rmvoverlap){ // left normally, reverse for right
       for(int i=1; i<=n; i++){
              int pos=(lower_bound(all(oc[c[i]]), i+1)-oc[c[i]].begin());
              if(pos<oc[c[i]].size()){
                     if(rmvoverlap) left+=(n-oc[c[i]][pos]+1)-sum(oc[c[i]][pos], sz-2);
                     else right+=(n-oc[c[i]][pos]+1);
              }
              if(rmvoverlap && nums.size() && nums[0]<=i) add(lr[nums[0]], -1), nums.pop_front();
       }
}

signed main(){
       cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>c[i], oc[c[i]].push_back(i);
       for(int i=1; i<=n; i++){
              if(done[c[i]]) continue;
              for(int j=oc[c[i]].size()-1; j>=1; j--) cl[oc[c[i]][j]]=oc[c[i]][j-1];
              for(int j=0; j<oc[c[i]].size()-1; j++) cr[oc[c[i]][j]]=oc[c[i]][j+1];
              done[c[i]]=1;
       }
       for(int i=1; i<=n; i++){
              if(cl[i]==0) continue;
              nums.push_back(cl[i]);
              lr[cl[i]]=i; add(i, 1);
       }
       sort(all(nums));
       procedure(true);
       // setup for right
       for(int i=1; i<=n; i++) oc[i].clear();
       for(int i=n; i>=1; i--) oc[c[i]].push_back(n-i+1);
       reverse(c+1, c+n+1);
       procedure(false);
       cout<<((n*(n-1))/2-(left+right))<<endl;
}

/*
when doing left
at pos i, the next pos to right with same val is j
count number of points in bit2 >=j
it suffices to subtract overlaps while counting left, then count right

*/



