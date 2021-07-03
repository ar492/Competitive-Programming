#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");


int main(){
int t;
fin>>t;
for (int i=0; i<t; i++){
    int n,m;
    fin>>n>>m;
    int matrix[n][m];
    for (int k=0; k<n; k++){
        for (int j=0; j<m; j++){
            int temp;
            fin>>temp;
            matrix[k][j]=temp;
        }
    }
    int a=0; int b=0;
    bool rowcheck=false;
    for (int k=0; k<n; k++){
        for (int j=0; j<m; j++){
            if(matrix[k][j]==1){rowcheck=true;}
        }
        if(rowcheck==false){a++;}
        rowcheck=false;
    }
    bool colcheck=false;
    for (int k=0; k<m; k++){
        for (int j=0; j<n; j++){
            if(matrix[j][k]==1){colcheck=true;}
        }
        if(colcheck==false){b++;}
        colcheck=false;
    }
    if(min(a,b)%2==1){cout<<"Ashish"<<endl;}
    else if (min(a,b)%2==0){cout<<"Vivek"<<endl;}
}
return 0;
}
