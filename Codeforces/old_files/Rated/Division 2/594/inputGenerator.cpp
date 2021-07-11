#include <iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<cmath>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#define pb push_back
#define INF (int)1e9
typedef long long ll;
using namespace std;

int main(){
  //  ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
   srand(time(NULL));
    ofstream fout("input.txt");
    int n; n=rand()%100000+1;
   // n=1000;
    fout<<n<<endl;
    int a;
    for(int i=0; i<n; i++){
        a=rand()%10000+1;
        if(i!=n-1){fout<<a<<" ";}
        else if (i==n-1){fout<<a<<endl;}
    }
return 0;
}


