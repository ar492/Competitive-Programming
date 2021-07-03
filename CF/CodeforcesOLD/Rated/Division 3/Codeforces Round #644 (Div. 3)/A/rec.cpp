#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("rec.in");


int main(){
    int t, a, b;
    fin>>t;
    for (int i=0; i<t; i++){
        fin>>a>>b;
        int small=min(a, b);
        int big=max(a,b);
        if (2*small>big){cout<<4*small*small<<endl;}
        else if (2*small<=big){cout<<big*big<<endl;}
    }

return 0;
}
