#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
ifstream fin("good.in");


int main(){
    int t=0; fin>>t;
    for (int i=0; i<t; i++){
    string s;
    fin>>s;
    int onecounter=0; int zerocounter=0;
    int prev=0;
    bool good=true;
    if (s[0]=='1' && s[s.length()-1]=='1' || 1<=s.find("1") && s.find("1")<=s.length()-2){good=false;}
    if (good==true){cout<<0<<endl;}
    else{
        for (int j=0; j<s.length(); j++){
            if (s[j]=='0'){zerocounter++;}
            else if (s[j]=='1'){onecounter++;}
        }
        if (onecounter>zerocounter){
            cout<<zerocounter<<endl;
        }
        else if (onecounter<=zerocounter){
            if(s[s.length()-1]=='1' || s[0]=='1'){cout<<onecounter-1<<endl;}
            else{cout<<onecounter<<endl;}
        }
    }
    }

return 0;
}
