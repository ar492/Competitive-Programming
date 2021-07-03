#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
struct ab{
int a;
int b;
};
int main(){///line could be increasing, or equal
int t; fin>>t;
for (int i=0; i<t; i++){
    int n; fin>>n;
    vector <ab> line;
    for (int k=0; k<n; k++){
        int temp=0; fin>>temp;
        ab myL;
        myL.a=temp;
        line.push_back(myL);
    }
    for (int k=0; k<n; k++){
        int temp=0; fin>>temp;
        line[k].b=temp;
    }
    bool onescheck=false;
    bool zeroescheck=false;
    for (int k=0; k<n; k++){
        if(line[k].b==1){onescheck=true;}
        if(line[k].b==0){zeroescheck=true;}
    }
    if(onescheck==true && zeroescheck==true){cout<<"Yes"<<endl;}
    else if(onescheck==false&&zeroescheck==true||(onescheck==true && zeroescheck==false)){
        bool check2=false;
        for (int k=1; k<n; k++){
            if(line[k].a<line[k-1].a){check2=true; break;}
        }
        if(check2==true){cout<<"No"<<endl;}
        else if (check2==false){cout<<"Yes"<<endl;}
    }
    line.clear();
}
return 0;
}
