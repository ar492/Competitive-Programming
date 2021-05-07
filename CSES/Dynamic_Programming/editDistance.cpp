#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int getmin(int a, int b, int c){return (min(min(a, b), c));}
int main() {
  string A, B;
  cin >> A >> B;
  int numcols=A.length()+1; int numrows=B.length()+1;
  int table[numrows][numcols];
  for (int i=0; i<numrows; i++){
    for (int j=0; j<numcols; j++){
      table[i][j]=0;
    }
  }
  for (int i=1; i<numrows; i++){table[i][0]=i;}
  for (int i=1; i<numcols; i++){table[0][i]=i;}
  for (int i=1; i<numrows; i++){
    for (int j=1; j<numcols; j++){
      if (A[j-1]!=B[i-1]){
        table[i][j]=getmin(table[i-1][j], table[i-1][j-1], table[i][j-1])+1;
        }
      else if (A[j-1]==B[i-1]){table[i][j]=table[i-1][j-1];}
      }
  }

  cout<<table[numrows-1][numcols-1]<<endl;

  return 0;
}
