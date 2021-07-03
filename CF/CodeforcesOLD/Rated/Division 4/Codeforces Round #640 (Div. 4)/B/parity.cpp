#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("parity.in");
vector <int> ans;

    void execute(int n, int k){
    ans.clear();
    for (int i=0; i<k-1; i++){ans.push_back(1);}
    int n2=n-(k-1);
    if (n2%2==1 && n2>0){
        cout<<"YES"<<endl;
        ans.push_back(n2);
        for (int i=0; i<ans.size(); i++){cout<<ans[i]<<" ";}
        cout<<endl;
        ans.clear();
    }
    else if (n2%2==0){
        ans.clear();
        for (int i=0; i<k-1; i++){ans.push_back(2);}
        n2=n-(k-1)*2;
        if (n2%2==0 && n2>1){
            cout<<"YES"<<endl;
            ans.push_back(n2);
            for (int i=0; i<ans.size(); i++){cout<<ans[i]<<" ";}
            cout<<endl;
            ans.clear();
        }
         else{ans.clear(); cout<<"NO"<<endl;}
    }
    }
int main(){
    int t=0;
    fin>>t;
    long long int n=0; int k=0;
    for (int q=0; q<t; q++){
    fin>>n>>k;
    if (k>n){cout<<"NO"<<endl;}
    else if (k==1){cout<<"YES"<<endl; cout<<n<<endl;}
    else{execute(n, k);}
    }
    return 0;
}
