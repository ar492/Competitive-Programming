// https://judge.yosupo.jp/problem/unionfind

// find_set and union_sets are O(alpha(n)) = O(1) 

#include <bits/stdc++.h>
using namespace std;

const int sz=200001;
int parent[sz], size[sz];
int n;

void initialize(){
    for(int i=0; i<n; i++){
        parent[i] = i; size[i] = 1;
    }
}
int find_set(int v) {//finds the parent (representative) of a set
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a); b = find_set(b);
    if (a != b) {
        if (size[a] < size[b]) // merge by size
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    cin>>n;
    initialize();
    int q; cin>>q;
    for(int i=0; i<q; i++){
        bool pr; int u,v; //pr = print
        cin>>pr>>u>>v;
        if(!pr) union_sets(u, v);
        else cout<<(find_set(u)==find_set(v))<<endl;
    }
return 0;
}
