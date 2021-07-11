#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("seq.in");

void disp(long long ans){
    if (ans>=0){cout<<ans%1000000007<<endl;}
    else if (ans<0){cout<<1000000007-abs(ans%1000000007)<<endl;}
}
int main(){
long long xF1=0; long long yF2=0; long long n=0;
fin>>xF1>>yF2>>n;
int modu=n%6;
if (modu==1){disp(xF1);} else if (modu==2){disp(yF2);}
else if (modu==3){disp(yF2-xF1);}
else if (modu==4){disp((-1)*xF1);}
else if (modu==5){disp((-1)*(yF2));}
else if (modu==0){disp((-1)*((yF2-xF1)));}

    return 0;
}
