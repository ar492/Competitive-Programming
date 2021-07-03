#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n; fin>>n;
    vector<int> sticks;
    for(int i=0; i<n; i++){
        int temp; fin>>temp; sticks.pb(temp);
    }
    sort(sticks.begin(), sticks.end());
    int h=0; int v=0;
    for(int i=0; i<n/2; i++){
        h+=sticks[i];
    }
    for(int i=n/2; i<n; i++){
        v+=sticks[i];
    }
    fout<<(ll)((ll)pow(h, 2)+(ll)pow(v, 2))<<endl;
    return 0;
}
