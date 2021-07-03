#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
    vector<int> arr;
    cin>>n>>k;
    sort(arr.begin(), arr.end());
    int counter=0;
    int index=arr.size()-1;
    for(int i=0; i<n; i++){
        if(index==0){break;}
        else{
        if(arr[index]<=k){counter++; k-=arr[index];}
        if(arr[index]>k){index--;}
        }
    }

    cout<<counter<<endl;
    return 0;
}
