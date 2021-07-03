#include <bits/stdc++.h>
#define LL long long
#define F first
#define S second
using namespace std;

int n;
deque<pair<LL, pair<LL, LL>>> cows; // <arrival time, < seniority, duration > >

void setup(){
    cin>>n;
    cows.resize(n);
    for(int i=0; i<n; i++){
        cin>>cows[i].F>>cows[i].S.S; //arrival time and duration
        cows[i].S.F=i; //seniority
    }
    sort(cows.begin(), cows.end());
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);
    setup();

    set<pair<LL, pair<LL, LL>>> line; // <seniority, < arrival time, duration > >
    LL nft=cows[0].F; //next free time
    LL mxw=0; //max wait time
    int done=0; //# cows finished visiting the pasture
    while(done!=n){
        //construct the line
        while(cows.size()>0 && cows[0].F<=nft){
            pair<LL, pair<LL, LL>> p=cows[0];
            swap(p.F, p.S.F);
            line.insert(p);
            cows.pop_front();
        }
        //take a cow to the pasture (From the line)
        if(line.size()>0){
            mxw=max(mxw, nft-(*line.begin()).S.F);
            nft+=(*line.begin()).S.S;
            line.erase(line.begin());
            done++;
        }
        else
            nft=cows[0].F; //if theres idle time
    }
    cout<<mxw<<endl;
return 0;
}

//this is my version of the official implementation..
//my solution idea was okay just the implementation was a challenge..
//tried using structs and pq with custom cmp but too much hassle
//official sol usage of pairs is much more elegant and nice
//could use std::tuple instead, perhaps
