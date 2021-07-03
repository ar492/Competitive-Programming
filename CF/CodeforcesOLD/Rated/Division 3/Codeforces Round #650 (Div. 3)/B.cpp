#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
ifstream fin("input.in");

int main(){
int t; fin>>t;
for (int w=0; w<t; w++){
    int n; fin>>n;
    int misplacedODD=0;
    int misplacedEVEN=0;
    for(int i=0; i<n; i++){
        int temp; fin>>temp;
        if(temp%2==0 && i%2!=temp%2){misplacedEVEN++;}
        if(temp%2==1 && i%2!=temp%2){misplacedODD++;}
    }
    ///cout<<misplacedODD<<" "<<misplacedEVEN<<endl;
    if(misplacedODD+misplacedEVEN==0){cout<<"0"<<endl;}
    else if(misplacedODD==misplacedEVEN){cout<<misplacedODD<<endl;}
    else if(misplacedODD!=misplacedEVEN){cout<<"-1"<<endl;}
    ///3 2 7 6
    ///0 1 2 3
}

return 0;
}
