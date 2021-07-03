#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

struct measurement{
    int day; int ID; int delta;
};
bool cmp(measurement a, measurement b){ return a.day < b.day; }

int main(){
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    int n, g; cin>>n>>g;
    vector<measurement> ms(n); // measurements <day, <ID, change>>

    map<int, int> rates; // <ID, rate>
    map<int, int, greater<int>> rCnt; // <rate, cnt>
    rCnt[g]=n+1; //+1  because:
    //"Note that Farmer John has a very large herd of cows, so although some of
    //them are noted in his log book as changing their milk production
    // there are always plenty of other cows around whose milk output level remains at G gallons."
    for(int i=0; i<n; i++){
        cin>>ms[i].day>>ms[i].ID>>ms[i].delta;
        rates[ms[i].ID]=g;
    }
    sort(ms.begin(), ms.end(), cmp);
    int adjustCnt=0;


    for(auto c:ms){
        int origRate=rates[c.ID];
        bool wastop=rCnt.begin()->F==origRate;
        int prevCnt=rCnt[origRate]; //previous display how many elements
        int isCnt=rCnt[origRate+c.delta]+1; //currentCnt of the changed rate
        rCnt[origRate+c.delta]++;

        if(rCnt[origRate]==1) rCnt.erase(origRate);
        else rCnt[origRate]--;
        rates[c.ID]+=c.delta;
        bool istop=rates[c.ID]==rCnt.begin()->F;

        if(wastop){
            if(!istop || prevCnt!=1 || isCnt!=1) adjustCnt++;
        }
        else if(istop) adjustCnt++;
    }
    cout<<adjustCnt<<endl;
return 0;
}
