#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

ifstream fin("input.in");

int main(){
vector<ll> arr;
ll n;
fin>>n;
for(int i=0; i<n; i++){ll temp; fin>>temp; arr.pb(temp);}
///for(int i=0; i<n; i++){cout<<arr[i]<<" ";}
sort(arr.begin(), arr.end());
int x=1;
int y=2;
int z=x&y;
cout<<z<<endl;
return 0;
}
