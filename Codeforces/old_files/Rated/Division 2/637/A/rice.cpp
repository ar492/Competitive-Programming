#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("rice.in");

string execute(int n, int a, int b, int c, int d){
if ((a+b)*n<(c-d)){return("NO");}
else if ((a-b)*n>(c+d)){return("NO");}
else{return("YES");}
}
int main(){
    int t, n, a, b, c, d;
    fin>>t;
    for (int i=0; i<t; i++){
        fin>>n>>a>>b>>c>>d;
        string temp=execute(n, a, b, c, d);
        if (i!=t-1){cout<<temp<<endl;}
        else if (i==t-1){cout<<temp;}
    }
    return 0;
}
