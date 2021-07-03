#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
ifstream fin("add.in");

struct interval{
int start;
int finish;
};
int main(){
int t=0;
fin>>t;
for (int q=0; q<t; q++){
    int n=0;
    fin>>n;
    long long arr[n];
    vector <interval> needTofix;
    for (int i=0; i<n; i++){
        int temp=0;
        fin>>temp;
        arr[i]=temp;
    }
    long long maxTillNow=-10000000000;
    long long amountInc=0;
    long long maxAmountInc=0;
    for (int i=0; i<n; i++){
        maxTillNow=max(arr[i], maxTillNow);
        amountInc=maxTillNow-arr[i];
        maxAmountInc=max(amountInc, maxAmountInc);
    }
    cout<<"MAXTILLNOW IS "<<maxTillNow<<endl;
   cout<<"maxAmountInc is "<<maxAmountInc<<endl;
   cout<<"log(maxAmountInc) is "<<log(maxAmountInc)<<endl;
   cout<<"log(2) is "<<log(2)<<endl;

    if (maxAmountInc!=0){cout<<"answer is "<<(int)((double)log(maxAmountInc)/log(2)+0.00001)+1<<endl;}
    else{cout<<0<<endl;}
    /*
    if(n==1){cout<<0<<endl;}
    else if (n==2){
        if(arr[0]<=arr[1]){cout<<"answer is "<<0<<endl;}
        else if (arr[0]>arr[1]){cout<<"answer is "<<(int)((double)log(abs(arr[0]-arr[1]))/log(2))+1<<endl;}
    }
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    for (int k=1; k<n-1; k++){
    cout<<"(not in condition) arr[k] is "<<arr[k]<<", arr[k-1] is "<<arr[k-1]<<" and k is "<<k<<endl;
        if (arr[k]<arr[k-1]){
            cout<<"arr[k] is "<<arr[k]<<", arr[k-1] is "<<arr[k-1]<<" and k is "<<k<<endl;
            ///cout<<"ello"<<endl;
            ///int i=k;
             interval myint;
             myint.start=k-1;
            while(arr[k]<arr[k-1]){
               /// i++;
                k++;
            }
           /// i++;
           /// myint.start=k;
            myint.finish=k-1;
           ///
            needTofix.push_back(myint);
        }
    }
    for (int i=0; i<needTofix.size(); i++){
        cout<<needTofix[i].start<<" "<<needTofix[i].finish<<endl;
    }
    if (needTofix.size()==0){cout<<"answer is "<<0<<endl;}
    cout<<endl;
    needTofix.clear();
    cout<<"end of input"<<endl;
    */
}
return 0;
}
