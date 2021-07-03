#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<long long, long long>> intervals;
bool placed(long long d){//O(n)
   // cout<<"called for d="<<d<<endl;
   // cout<<"placing at "<<intervals[0].first<<endl;
    long long prev=intervals[0].first;
    long long cnt=1;//number of cows placed so far
    for(pair<long long, long long> i:intervals){
       // cout<<i.first<<" "<<i.second<<" is the current interval"<<endl;
        long long cur=-1; //current start
        if(i.first<=prev+d && i.second>=prev+d) cur=prev+d;
        else if(i.first>prev+d) cur=i.first;
        if(cur!=-1){//if cow(s) can fit in this interval
          //  cout<<"placing "<<(i.second-cur)/d + 1<<" cows "<<endl;
            cnt+=(i.second-cur)/d + 1;
            prev=i.first+((i.second-cur)/d)*d;
            //cout<<"prev is "<<prev<<endl;
        }

    }
    return (cnt>=n ? 1:0);
}
int main(){
    ifstream cin("socdist.in"); ofstream cout("socdist.out");
    cin>>n>>m;
    intervals.resize(m);
    for(int i=0; i<m; i++) cin>>intervals[i].first>>intervals[i].second;
    sort(intervals.begin(), intervals.end()); //sorts by first value of pair
    //(intervals are non-overlapping so its ok)
    long long l=1; long long r=1e18;
    long long d;
    while(l<=r){//O(log(n))
        long long m=(l+r)/2;
        //cout<<"l, r: "<<l<<" "<<r<<endl;
        //cout<<"placed("<<m<<") is "<<placed(m)<<endl;
        if(placed(m)){
            d=m; l=m+1;
        }
        else r=m-1;
    }
    cout<<d<<endl;
    return 0;
}
