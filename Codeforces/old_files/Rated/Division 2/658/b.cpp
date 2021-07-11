#include <iostream>
#include<set>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main() {
  multiset<int> s;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
        s.insert(i*j);
    }
  }
  for(int i=0; i<=100; i++){
    if((int)(s.count(i)!=0)){
        cout<<"Occurence of "<<i<<" is: "<<s.count(i)<<endl;
    }
  }
return 0;
}
