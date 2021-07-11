#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("japan.in");
int main(){
    long long n, x; fin>>n>>x;
    long long int enc[n];
    int temp=0;
    for (int i=0; i<n; i++){fin>>temp; enc[i]=temp;}
    long long sum=0;
    for (int i=0; i<n; i++){sum+=enc[i];}
    if (sum+(n-1)==x){cout<<"YES";}else{cout<<"NO";}
    return 0;
}
