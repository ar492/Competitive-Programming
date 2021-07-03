#include <bits/stdc++.h>
using namespace std;

int cards1[(int)1e5+1], cards2[(int)1e5+1];
int main(){
    ifstream cin("cardgame.in");
    ofstream cout("cardgame.out");

    int n; cin>>n;
    for(int i=0; i<n; i++){
        int u; cin>>u;
        if(i<n/2) cards1[u]=1;
        else cards2[u]=1;
    }
    int bcnt=0;
    for(int i=1; i<=2*n; i++){
        if(cards1[i]+cards2[i]==0){//bessies card
            if(bcnt<n/2) cards2[i]=2;
            else cards1[i]=2;
            bcnt++;
        }
    }
    //for first half
    // looking for 1 2
    int ans=0;
    {
        stack<int> ones, twos;
        for(int i=1; i<=2*n; i++){
            if(cards1[i]==1) ones.push(1);
            else if(cards1[i]==2){
                if(!ones.empty()){
                    ones.pop();
                    ans++;
                }
                else twos.push(2);
            }
        }
    }
    // for second half
    // looking for 2 1
    {
        stack<int> ones, twos;
        for(int i=1; i<=2*n; i++){
            if(cards2[i]==2) twos.push(2);
            else if(cards2[i]==1){
                if(!twos.empty()){
                    twos.pop();
                    ans++;
                }
                else ones.push(1);
            }
        }
    }
    cout<<ans<<endl;


return 0;
}
