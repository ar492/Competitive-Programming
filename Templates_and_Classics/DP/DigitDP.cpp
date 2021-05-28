/*

How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x

use digit DP

*/


#include<bits/stdc++.h>
/*

do complexity analysis

*/

#define int long long
using namespace std;

int dp[19][19][2];
/// dp[p][c][f] = Number of valid numbers <= b FROM this state
/// p = current position
/// c = number of times we have placed the digit d so far
/// s = the number we are building has already become smaller than b?

string b; char d; int k;
int ops=0;
int f(int pos=0, int cnt=0, bool s=0){
       ops++;

       if(cnt>k) return 0;
       if(pos==b.size()) return(cnt==k);
       if(dp[pos][cnt][s] != -1) return dp[pos][cnt][s];


       char limit=(s==false ? b[pos] : '9');
       int sum=0;
       for(char i='0'; i<=limit; i++)
              sum += f(pos+1, cnt+(i==d), (i<b[pos]) || s);

       dp[pos][cnt][s]=sum;
}

signed main(){
       cin.tie(0)->sync_with_stdio(0);
       memset(dp, -1, sizeof(dp));
       b="111"; d='1'; k=2; // how many integers in range [0, 111] have exactly two 1's (3: 11, 101, 110)
       cout<<f()<<endl;
       cout<<ops<<endl;
}
