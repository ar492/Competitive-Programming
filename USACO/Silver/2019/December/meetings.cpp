using namespace std;
#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(), (x).end()
int n,l;

struct cow{ int dir, time, x, w; };
bool posSort(cow a, cow b){ return a.x<b.x; };

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	ifstream cin("meetings.in"); ofstream cout("meetings.out");
        cin>>n>>l;
        deque<cow> cows;
        vector<int> weights, lefts;
        vector<pair<int, int>> times; // <time, direction>
        int sumweights=0;
        for(int i=0; i<n; i++){
                int w,x,d; cin>>w>>x>>d; sumweights+=w;
                cows.push_back({d, -1, x, w});
                if(d==1) times.push_back({l-x, 1});
                else{ times.push_back({x, -1}); lefts.push_back(x); }
        }
        sort(all(times));
        sort(all(cows), posSort);
        deque<cow> cowscopy=cows;
        sort(all(lefts));
        int weight=0, T=0;
        for(auto time:times){
                if(time.second==1){ weight+=cowscopy[cowscopy.size()-1].w; cowscopy.pop_back(); }
                else{ weight+=cowscopy[0].w; cowscopy.pop_front(); }
                if(weight>=sumweights/2 + (sumweights%2)){
                        T=time.first; break;
                }
        }
        int col=0;
        for(int i=0; i<n; i++){
                if(cows[i].dir==1){
                        auto it1=lower_bound(all(lefts), cows[i].x);
                        auto it2=upper_bound(all(lefts), cows[i].x+2*T);
                        if(it2==lefts.begin()) col+=lefts.size();
                        else if(*it1-cows[i].x<=2*T) col+= (--it2-lefts.begin())-(it1-lefts.begin())+1;
                }

        }
        cout<<col<<endl;
        return 0;
}
