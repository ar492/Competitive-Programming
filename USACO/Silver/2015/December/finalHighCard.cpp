#include <bits/stdc++.h>
using namespace std;

/*
int n,cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("highcard.in"); ofstream cout("highcard.out");
    cin>>n;
    string a=string(2*n, '0');
    for(int i=0; i<n; i++){
        int x; cin>>x; x--;
        a[x]='1';
    }
    set<int> b, e; //bessie and elsie
    for(int i=0; i<2*n; i++){
        if(a[i]=='1') e.insert(i+1);
        else b.insert(i+1);
    }
    for(int i:e)
        if(b.lower_bound(i+1)!=b.end()){
            cnt++; b.erase(b.lower_bound(i+1));
        }
    cout<<cnt<<endl;
return 0;
}

*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("highcard.in"); ofstream cout("highcard.out");
    int n; cin>>n;
    deque<int> e, b;
    set<int> eitems;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        e.push_back(x-1);
        eitems.insert(x-1);
    }
    for(int i=0; i<2*n; i++) if(!eitems.count(i)) b.push_back(i);

    sort(e.begin(), e.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int cnt=0;
    for(int i=0; i<n; i++){
        if(b[0]>e[0]){ cnt++; b.pop_front(); }
        e.pop_front();
    }
    cout<<cnt<<endl;
return 0;
}
