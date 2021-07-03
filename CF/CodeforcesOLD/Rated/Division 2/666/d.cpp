#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
#define deb(x) cout<<#x<<" "<<x<<endl;
typedef long long ll;
using namespace std;

void showpq(priority_queue <int> gq)
{
    priority_queue <int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

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
            showpq(pq);
            if(!turn){prevT=pq.top()-1; cout<<"prevT is "<<prevT<<endl;}
            else if(turn){prevHL=pq.top()-1; cout<<"prevHL is "<<prevHL<<endl;}
            cout<<"popping "<<pq.top()<<endl;
            pq.pop();
            if(cnt==1 && turn==1)
            {
                if(prevT>0) pq.push(prevT);
                cout<<"pushing prevT("<<prevT<<")"<<endl;
            }
            else if(cnt==2 && turn==0){
                if(prevHL>0) pq.push(prevHL);
                cout<<"pushing prevHL("<<prevHL<<")"<<endl;
                cnt=0;
            }
            cnt++;
            turn=!turn;
        }
        cout<<"here: "<<(turn ? "T":"HL")<<endl;
    }
return 0;
}
