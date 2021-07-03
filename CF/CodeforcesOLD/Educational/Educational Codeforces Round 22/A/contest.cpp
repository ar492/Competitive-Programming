///incorrect test case 7
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("contest.in");
struct interval{long long int l; long long int r;};
int main(){
    int n=0; fin>>n;
    vector <int> solvetimes;
    int temp; for (long long int i=0; i<n; i++){fin>>temp; solvetimes.push_back(temp);}

    int m=0; fin>>m;
    vector <interval> intervals;
    interval iv;
    for (int i=0; i<m; i++){fin>>temp; iv.l=temp; fin>>temp; iv.r=temp; intervals.push_back(iv);}
    long long int sum=0;
    for (int i=0; i<solvetimes.size(); i++){sum+=solvetimes[i];}
    bool check=false;
    for (int i=0; i<intervals.size(); i++){
        if (sum>=intervals[i].l && sum<=intervals[i].r){check=true; cout<<sum<<endl; break;}
    }
    if (check==false){cout<<-1<<endl;}
    return 0;
}
