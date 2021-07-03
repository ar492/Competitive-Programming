#include <bits/stdc++.h>
#define For(i,a,b) for (ll i = (a); i < (b); i++)
#define pb push_back
typedef long long ll;
using namespace std;

ifstream fin("input.txt");

int main(){
int t=0;
fin>>t;
For(i, 0, t){
ll a, b;
fin>>a>>b;
cout<<min(min(a, b), ((a+b)/3))<<endl;
}
return 0;
}
