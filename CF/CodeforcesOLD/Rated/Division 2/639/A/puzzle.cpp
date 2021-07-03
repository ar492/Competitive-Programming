#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("puzzle.in");

int main(){
int t;
fin>>t;

for (int i=0; i<t; i++){
    int n=0; int m=0;
    fin>>n>>m;
    if (n==2 && m==3 ||m==2 && n==3 || m>=3 && n>=3){cout<<"NO"<<endl;}
    else{cout<<"YES"<<endl;}
}

return 0;
}
