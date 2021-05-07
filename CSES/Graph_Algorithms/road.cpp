#include <bits/stdc++.h>
using namespace std;

const int SIZE=100001;
int parent[SIZE];
int size[SIZE];
int n;

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void initialize(){
    for(int i=0; i<n; i++) make_set(i);
}

int find_set(int v) {//finds the parent (representative) of a set
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main(){
    cin>>n;
    initialize();
    int m; cin>>m;
    int mx=1; int cc=n;
    while(m--){
        int a,b; cin>>a>>b; --a; --b;
        if(find_set(a)!=find_set(b)) cc--;
        union_sets(a, b);
        mx=max(mx, size[find_set(a)]);
        cout<<cc<<" "<<mx<<endl;
    }


return 0;
}
