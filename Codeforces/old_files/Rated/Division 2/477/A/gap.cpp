///many edge case fails
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("gap.in");

int main(){
    vector <int> times;
    int n, s, h, m;
    fin>>n>>s;
    for (int i=0; i<n; i++){
        fin>>h>>m;
        times.push_back(60*h+m);
    }
    if (times[0]>=s+1){cout<<"0 0";}
    else if (n==1){
            int temp=times[0]+s;
            if (temp%60+1==60){cout<<temp/60+1<<" "<<(temp+1)%60;}
            else{cout<<temp/60<<" "<<(temp+1)%60;}
    }
    else{
    for (int i=1; i<times.size(); i++){
            if (times[i]-times[i-1]-2>=2*s){
                int temp=times[i-1]+s;
                if (temp%60+1==60){cout<<temp/60+1<<" "<<(temp+1)%60;}
                else{cout<<temp/60<<" "<<(temp+1)%60;}
                break;
            }
            else if (i==times.size()-1){
                int temp=times[i]+s;
                if (temp%60+1==60){cout<<temp/60+1<<" "<<(temp+1)%60;}
                else{cout<<temp/60<<" "<<(temp+1)%60;}
            }
    }
    }
    return 0;
}
