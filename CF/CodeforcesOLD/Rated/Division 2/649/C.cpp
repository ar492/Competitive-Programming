#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
ifstream fin("input.in");
int binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int main(){
int n;
fin>>n;
vector<int> arr;
vector<int> b;
for (int i=0; i<n; i++){
    int temp; fin>>temp; arr.pb(temp);
}
for (int i=0; i<n; i++){
    cout<<arr[i]<<" ";
}cout<<endl;
int index=binarySearch(arr, 0, arr.size()-1, 2)-1;
for (int i=0; i<n; i++){
    if(arr[i]==0){if(binarySearch(arr, 0, arr.size()-1, 1)==-1){b.pb(1);}else{b.pb(0);}}
}
return 0;
}
