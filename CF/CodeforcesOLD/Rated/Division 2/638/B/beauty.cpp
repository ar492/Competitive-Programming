#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;

ifstream fin("beauty.in");
vector <int> elements;
set <int> d;

void dCount(int N, int K){
for (int i=0; i<elements.size(); i++){d.insert(elements[i]);}
set<int>::iterator it=d.begin();
for (;it!=d.end(); it++){cout<<*it<<" ";}cout<<endl;
}

void execute(int N, int K){
    if (N==K){
        /*cout<<N<<endl;
        for (int i=0; i<N; i++){cout<<elements[i]<<" ";}
        cout<<endl;*/
    }
    else {
    dCount(N, K);
    if (d.size()>k){cout<<-1<<endl;}
    else{

    }
    }

}
int main(){
int t, n, k, trash;
fin>>t;
//cout<<t<<endl;
for (int i=0; i<t; i++){
fin>>n>>k;
for (int j=0; j<n; j++){fin>>trash; elements.push_back(trash);}
execute(n, k);
//cout<<n<<" "<<k<<endl;
//for (int j=0; j<elements.size(); j++){cout<<elements[j]<<" ";}
//cout<<endl;
elements.clear();
d.clear();
}

return 0;
}
