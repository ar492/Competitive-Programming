#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
ifstream fin("clock.in");
int numsindexcounter=0;
int uncommonCheck(string a, string b){
if (b.length()==0){return -1;}
else {
int counter=0;
for (int i=0; i<a.length(); i++){
       // cout<<a[i]<<b[i]<<endl;
    if (a[i]=='0' && b[i]=='1'){counter++;}
    else if (a[i]=='1' && b[i]=='0'){return -1;}
}
return counter;
}
}

string digitFind(int digit){
if (0==digit){return "1110111";}
else if (1==digit){return "0010010";}
else if (2==digit){return "1011101";}
else if (3==digit){return "1011011";}
else if (4==digit){return "0111010";}
else if (5==digit){return "1101011";}
else if (6==digit){return "1101111";}
else if (7==digit){return "1010010";}
else if (8==digit){return "1111111";}
else if (9==digit){return "1111011";}
else {return("");}
}

int main(){
int n,k;
fin>>n>>k;
string config[n];
vector <int> nums;
string temp1;
for (int i=0; i<n; i++){fin>>temp1; config[i]=temp1;}
///cout<<"config begin"<<endl;
///for (int i=0; i<n; i++){cout<<config[i]<<endl;}
///cout<<"config end"<<endl;
//cout<<"UNCOMMON CHECK"<<uncommonCheck("0010010", "1111011");
for (int i=0; i<n; i++){
    //bool check=false;
    for (int j=8; j>=0; j--){///make function to do recursively
            int temp=uncommonCheck(config[i], digitFind(j+1));
            cout<<"("<<i<<", "<<j<<")"<<endl; cout<<"the string of comparison: "<<config[i]<<" digit:"<<j+1<<" = "<<digitFind(j+1)<<endl;
            if (temp<=k && temp!=-1){
                    k=k-temp; nums.push_back(j+1);
                    //check=true;
                    break;
            }
            cout<<temp<<endl;
          //  if (temp==1){cout<<"("<<i<<", "<<j<<")"<<endl; cout<<config[i]<<" "<<digitFind(j+1)<<endl;}
    }
    if (i==n-1){
            cout<<"ONLY ONCE?"<<endl;
            if (k!=0){cout<<-1<<endl;}
            else if (k==0) {for (int q=0; q<nums.size(); q++){cout<<nums[q];}}
    }
}

return 0;
}


