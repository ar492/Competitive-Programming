#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("alchemy_input.txt");
    ofstream cout("alchemy_output.txt");
    int t; cin>>t;
    for(int q=0; q<t; q++){
        cout<<"Case #"<<q+1<<": ";
        int n; cin>>n;
        string x; cin>>x;
        cout<<(abs(count(x.begin(), x.end(), 'A')-count(x.begin(), x.end(), 'B'))<=1 ? "Y" : "N")<<endl;
    }
return 0;
}
