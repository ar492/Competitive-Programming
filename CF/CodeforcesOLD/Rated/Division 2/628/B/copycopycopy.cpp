#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n; cin>>n;
        set<int> a;
        for(int i=0; i<n; i++){
            int x; cin>>x; a.insert(x);
        }
        cout<<min((int)a.size(), n)<<endl;
    }
    return 0;
}
