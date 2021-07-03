#include <bits/stdc++.h>
using namespace std;

ifstream fin("lostcow.in"); ofstream fout("lostcow.out");
int x,y,dist;

void travel(int from, int delta){
    int i=from;
    while(i!=x+delta){
        dist++;
        if(i==y){
            fout<<dist-1<<endl; exit(0);
        }
        if(delta<0) i--;
        else i++;
    }
    travel(i, delta*(-2));
}
int main(){
    fin>>x>>y;
    travel(x, 1);
return 0;
}
