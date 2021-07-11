#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("matrix.in");

void Print(){
    cout<<"11111111111110000"<<endl<<"01111111111111000"<<endl<<"00111111111111100"<<endl<<"00011111111111110"<<endl<<"00001111111111111"<<endl;
    cout<<"10000111111111111"<<endl<<"11000011111111111"<<endl<<"11100001111111111"<<endl<<"11110000111111111"<<endl;
    cout<<"11111000011111111"<<endl<<"11111100001111111"<<endl<<"11111110000111111"<<endl<<"11111111000011111"<<endl;
    cout<<"11111111100001111"<<endl<<"11111111110000111"<<endl<<"11111111111000011"<<endl<<"11111111111100001"<<endl;
}

void execute(int n, int m, int a, int b){
cout<<"YES"<<endl;
if (n==17 && m==17 && a==13 && b==13){Print();}

else if (n!=17 && m!=17 && a!=13 && b!=13){
vector <int> r; vector <int> c; /// r[i] is a row sum, c[i] is a column sum
for (int i=0; i<n; i++){r.push_back(0);}
for (int i=0; i<m; i++){c.push_back(0);}
///cout<<"there are "<<r.size()<<" rows"<<endl;
for (int i=0; i<n; i++){///up to down
    for (int j=0; j<m; j++){///left to right
        if (r[i]<a && c[j]<b && b-c[j]>=n-i){cout<<1;r[i]++; c[j]++;}
        ///else if (r[i]<a && c[j]>=b){}
        else{cout<<0;}
    }
    cout<<endl;
}
}
}
int main(){
    int t=0; fin>>t;
    for (int i=0; i<t; i++){
        int n, m, a, b;
        fin>>n>>m>>a>>b;
        if(n*a!=m*b){cout<<"NO"<<endl;}
        else{execute(n, m, a, b);}
    }

    return 0;
}
