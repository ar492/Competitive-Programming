#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("wilbur.in");

int main(){

    long long int n,b[200005],val = 0,cnt = 0;
    fin >> n;
    for(int i = 0; i < n; i++)fin >> b[i];

    val = 0;

    for(int i = 0; i < n; i++){

        if(val < b[i]){
            while(val != b[i]){val++;cnt++;}
        }
        else if(val > b[i]){
            while(val != b[i]){val--;cnt++;}
        }
    }
    cout << cnt << endl;
    return 0;
}
