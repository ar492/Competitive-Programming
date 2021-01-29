#include<bits/stdc++.h>
#define V1 first
#define V2 second
using namespace std;

const int sz=2e5+2;
set<int> pos[sz];
int cmps[sz], a[sz], n, k;
pair<int, int> swaps[sz];

void perm(){
        for(int j=0; j<k; j++){
                auto i=swaps[j];
                swap(a[i.V1], a[i.V2]);
        }
}

void components(){
        int cur=1;
        for(int i=1; i<=n; i++){
                if(cmps[i]) continue;
                int where=i; cmps[i]=cur;
                while(a[where]!=i) cmps[where=a[where]]=cur;
                cur++;
        }
        for(int i=1; i<=n; i++){ pos[cmps[i]].insert(i); a[i]=i; }
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0; i<k; i++) cin>>swaps[i].V1>>swaps[i].V2;
	for(int i=1; i<=n; i++) a[i]=i;
        perm(); components();
        for(int j=0; j<k; j++){
                auto i=swaps[j];
                pos[cmps[a[i.V1]]].insert(i.V2);
                pos[cmps[a[i.V2]]].insert(i.V1);
                swap(a[i.V1], a[i.V2]);
        }
        for(int i=1; i<=n; i++) cout<<pos[cmps[i]].size()<<'\n';
}
