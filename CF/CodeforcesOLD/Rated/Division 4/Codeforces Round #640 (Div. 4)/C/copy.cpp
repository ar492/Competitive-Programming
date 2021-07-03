#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("div.in");

int main(){
    long long t=0;
    fin>>t;
    vector <int> ans;
    long long n=0; long long k=0;
    for (int q=0; q<t; q++){
    long long counter=1;
    fin>>n>>k;
    if (n==2){cout<<2*k-1<<endl;}
    else{
    for (long long x=1; x<100000000; x++){
        if (k-n<(n-1)*x && (n-1)*x<k+n){
            cout<<(n-1)*x+(x-1)+k-x*(n-1)+1<<endl;
            break;
        }
    }
    ans.clear();
    }
    }
    return 0;
}
