#include <iostream>
#include <fstream>
typedef long long ll;

using namespace std;

ifstream fin("binary.in");

int main(){

int t;
ll x, y, a, b;
int xc=0; int yc=0;
int counter=0;
fin>>t;

for (int i=0; i<t; i++){
    fin>>x>>y>>a>>b;
    if (x>y){swap(x,y);}
    cout<<min(a*(y-x)+b*x, a*(x+y))<<endl;
}
return 0;
}
