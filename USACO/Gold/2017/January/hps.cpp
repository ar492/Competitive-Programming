#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int szN=1e5+5, szK=25;
int dp[szN][szK][3], n, k;
char input[szN];
map<char, char> win={{'H', 'S'}, {'S', 'P'}, {'P', 'H'}};
map<int, char> il={{0, 'H'}, {1, 'P'}, {2, 'S'}};

signed main(){
       ifstream cin("hps.in"); ofstream cout("hps.out");
	cin.tie(0)->sync_with_stdio(0);
       cin>>n>>k; k++; // because of impl
       for(int i=1; i<=n; i++) cin>>input[i];
       for(int pos=1; pos<=n; pos++){
              for(int K=1; K<=k; K++){
                     for(int move=0; move<3; move++) //extend
                            dp[pos][K][move]=max(dp[pos][K][move], dp[pos-1][K][move]+(input[pos]==win[il[move]]));
                     if(pos!=1 && K!=1)
                            for(int move=0; move<3; move++) // transition from move2 to move in Kth transition
                                   for(int move2=0; move2<3; move2++)
                                          if(move!=move2)
                                                 dp[pos][K][move]=max(dp[pos][K][move], dp[pos-1][K-1][move2]+(input[pos]==win[il[move]]));
              }
       }
       int ans=0;
       for(int K=1; K<=k; K++)
              for(int move=0; move<3; move++)
                     ans=max(ans, dp[n][K][move]);
       cout<<ans<<"\n";
}
// actually read tips.txt
