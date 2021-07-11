#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("round.in");
vector <int> answer;
    void execute(int n, int x){
        if (n<=10 && n!=0){answer.push_back(n);}//cout<<1<<endl; cout<<n;}
        else if (n==0){}
        else{
        do{
            x*=10;
        }while(n/x!=0);
        x/=10;
       // cout<<(n/x)*x<<" ";
        if ((n/x)*x!=0){answer.push_back((n/x)*x);}
        //cout<<"X is "<<x<<endl;
        //cout<<"N is "<<n<<endl;
        n=n-(n/x)*x;
        //cout<<"N is now "<<n<<endl;;
        //cout<<n<<" ";
        execute(n, 1);
        }
    }
int main(){
    int t=0;
    fin>>t;
    int n=0;
    for (int i =0; i<t; i++){
    fin>>n;
   // cout<<n<<endl;
    if (n<=10){cout<<1<<endl; cout<<n<<" ";}
    else{
        execute(n, 1);
        cout<<answer.size()<<endl;
        for (int q=0; q<answer.size(); q++){{cout<<answer[q]<<" ";}}
    }
    cout<<endl;
    answer.clear();
    }
    return 0;
}
