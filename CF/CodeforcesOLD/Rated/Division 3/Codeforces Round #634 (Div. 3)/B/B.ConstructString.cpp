#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
int t; cin>>t;
for(int q=0; q<t; q++){
    int n,a,b; cin>>n>>a>>b;
    int i=0;
    while(i!=n){
        cout<<(char)(i%b+97);
        i++;
    }cout<<endl;
}

  return 0;
}
