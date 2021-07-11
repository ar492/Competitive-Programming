#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("ath.in");

void execute(vector <int> s){

int diff=1003;
for (int i=1; i<s.size(); i++){
    diff=min(diff, s[i]-s[i-1]);
}
cout<<diff<<endl;
}
int main(){
    vector <int> s;
    int t, n, input;
    fin>>t;
    for (int i=0; i<t; i++){
        fin>>n;
        for (int j=0; j<n; j++){
            fin>>input;
            s.push_back(input);
        }
        sort(s.begin(), s.end());
        execute(s);
        s.clear();
    }

return 0;
}
