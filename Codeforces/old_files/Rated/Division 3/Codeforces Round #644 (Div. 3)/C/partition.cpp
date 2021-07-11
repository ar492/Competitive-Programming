#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("par.in");

bool check=false;
void execute(vector <int> a){
check=false;
while(check==false){
int numconsec=1;
int numevenNONconsec=0;
bool x=false;
for (int i=0; i<a.size()-1; i++){
///cout<<a[i]<<" ";
        if(a[i+1]-a[i]==1){x=true; numconsec++;}
        else if (a[i]%2==0){numevenNONconsec++;}
}
if(a[a.size()-1]%2==0){numevenNONconsec++;}
if(x==false){numconsec=0;}
//cout<<numconsec<<" consecutive numbers"<<endl;
//cout<<numevenNONconsec<<" even, non consecutive numbers"<<endl;
///cout<<numevenNONconsec<<" this is numevennonconsec"<<endl;
if (numconsec%2==0 && numevenNONconsec%2==0 && check==false){check=true; cout<<"YES"<<endl;}

    numconsec=1;
    int numeven=0;
    x=false;
for (int i=0; i<a.size()-1; i++){
        if (a[i]%2==0){numeven++;}
        else if(a[i+1]-a[i]==1){x=true; numconsec++;}
}
if(a[a.size()-1]%2==0){numeven++;}
if(x==false){numconsec=0;}
if (numeven%2==0 && numconsec%2==0 && check==false){check=true;cout<<"YES"<<endl;}

    //cout<<"NO"<<endl;

numconsec=1;
int numoddNONconsec=0;
x=false;
for (int i=0; i<a.size()-1; i++){
        if(a[i+1]-a[i]==1){x=true; numconsec++;}
        else if (a[i]%2==1){numoddNONconsec++;}
}
if(a[a.size()-1]%2==1){numoddNONconsec++;}
if(x==false){numconsec=0;}
if (numconsec%2==0 && numoddNONconsec%2==0 && check==false){check=true;cout<<"YES"<<endl;}
        numconsec=1;
    int numodd=0;
x=false;
for (int i=0; i<a.size()-1; i++){
        if (a[i]%2==1){numodd++;}
        else if(a[i+1]-a[i]==1){x=true; numconsec++;}
}
if(x==false){numconsec=0;}
if(a[a.size()-1]%2==1){numodd++;}
if (numodd%2==0 && numconsec%2==0 && check==false){check=true;cout<<"YES"<<endl;}
if(check==false){check=true; cout<<"NO"<<endl;}
}
}
int main(){
    vector <int> a;
    int t, n, input;
    fin>>t;
    for (int i=0; i<t; i++){
        fin>>n;
        for (int j=0; j<n; j++){
            fin>>input;
            a.push_back(input);
        }
        sort(a.begin(), a.end());
        execute(a);
        a.clear();
    }

return 0;
}
