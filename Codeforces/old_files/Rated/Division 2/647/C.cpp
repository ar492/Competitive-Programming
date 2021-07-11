#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.in");

long long binaryCompare(long long a, long long b)
{
    long long binaryNum1[61];
    long long binaryNum2[61];
    for (long long i=0; i<61; i++){binaryNum1[i]=0; binaryNum2[i]=0;}
    long long i=0;
    while (a>0) {
        binaryNum1[i] = a % 2;
        a = a / 2;
        i++;
    }
    long long q=0;
    while (b>0) {
        binaryNum2[q]=b%2;
        b=b/2;
        q++;
    }
   /// cout<<"i q is "<<i<<" "<<q<<endl;
    long long maximum=max(i, q);
    long long counter=0;
    ///for (long long j=maximum-1; j>=0; j--){cout<<binaryNum1[j];}cout<<endl;
    ///for (long long j=maximum-1; j>=0; j--){cout<<binaryNum2[j];}cout<<endl;
    for (long long j=maximum-1; j>=0; j--){
        if (binaryNum1[j]!=binaryNum2[j]){counter++;}
    }
    return counter;
}

void execute(long long n){

long long accum=0;
///for (long long i=1; i<n+1; i++){
for (long long i=1; i<200; i++){
    ///cout<<"binary compare "<<i<<" "<<i-1<<" is ::: "<<binaryCompare(i, i-1)<<endl;
    cout<<binaryCompare(i, i-1)<<" ";
  ///  accum+=binaryCompare(i, i-1);
}
cout<<accum<<endl;
}


int main(){
long long t=0;
fin>>t;
for (long long z=0; z<t; z++){
    long long n; fin>>n;
    execute(n);
    cout<<"END CASE ------------------------------------------------------------"<<endl;
}

return 0;
}



