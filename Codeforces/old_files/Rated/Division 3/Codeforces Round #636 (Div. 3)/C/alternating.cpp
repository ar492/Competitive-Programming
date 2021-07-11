
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("alternating.in");

bool checkparity(vector <long long> x, int k){if (x[k]<0){return false;} else if (x[k]>0){return true;}}
int main() {
long long t=0; fin>>t;
//cout<<t<<endl;
long long length=0;
vector <long long> nums;
vector <long long> formation;
for (long long q=0; q<t; q++){
    cout<<"Test "<<q+1<<endl;
    fin>>length;
    for (long long j=0; j<length; j++){
        long long temp=0;
        fin>>temp;
        nums.push_back(temp);
    }
    for (long long i=0; i<nums.size(); i++){cout<<nums[i]<<" ";}cout<<endl;
    if (nums.size()==1){cout<<nums[0]<<endl;}
    else if (nums.size()==2){
        if (checkparity(nums, 0)!=checkparity(nums, 1)){cout<<nums[0]+nums[1]<<endl;}
        else{cout<<max(nums[0], nums[1])<<endl;}
    }
    else{
    long long maximum=-1000000001;
    for (long long i=0; i<nums.size(); i++){
        if (i!=nums.size()-1){
            if (checkparity(nums,i)==checkparity(nums, i+1)){long long temp=max(nums[i], nums[i+1]); maximum=max(temp, maximum); if(i==nums.size()-2){formation.push_back(maximum);}}
            else if (checkparity(nums, i)!=checkparity(nums, i+1)){
                if (i==0){formation.push_back(nums[i]); maximum=-1000000001;}
                else if (i!=0){
                    if (i==nums.size()-2){formation.push_back(nums[i+1]);}
                    if (checkparity(nums, i)!=checkparity(nums, i-1)){formation.push_back(nums[i]); maximum=-1000000001;}
                    else{if (maximum!=0){formation.push_back(maximum);}maximum=-1000000001;}
                }
        }
    }
    }
    maximum=0;
    long long accum=0;
     for (long long i=0; i<formation.size(); i++){cout<<formation[i]<<" ";}cout<<endl;
    for (long long i=0; i<formation.size(); i++){accum+=formation[i];}cout<<accum<<endl;

    }
formation.clear();
nums.clear();
}
return 0;
}
