#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        priority_queue<int> pq; //max priority
        for(int i=0; i<n; i++){
            int u; cin>>u; pq.push(u);
        }
        bool turn=0; // T is 0, HL is 1
        int cnt=0;
        int prevT, prevHL;
        while(pq.size()!=0){
            if(!turn){prevT=pq.top()-1;}
            else if(turn){prevHL=pq.top()-1;}
            pq.pop();
            if(cnt==1 && turn==1)
                if(prevT>0) pq.push(prevT);

            else if(cnt==2 && turn==0){
                if(prevHL>0) pq.push(prevHL);
                cnt=0;
            }
            cnt++;
            turn=!turn;
        }
        cout<<(turn ? "T":"HL")<<endl;
    }
return 0;
}
