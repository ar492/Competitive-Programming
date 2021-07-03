#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void execute(vector <int> line, int n){
int turn=0; int movescount=0;
int a=0; int b=0;
int aturn=0; int bturn=0;
    do{
        if (turn%2==0){///Alice's turn
            if (b==0){a+=line[0]; aturn=line[0]; line.erase(line.begin());}
            else if (b!=0){
                while(aturn<=bturn && line.size()!=0){
                    a+=line[0];
                    aturn+=line[0];
                    line.erase(line.begin());
                }
                    bturn=0;
            }
            turn++;
        }
        else if (turn%2==1){///Bob's turn
            while(bturn<=aturn && line.size()!=0){
                b+=line[line.size()-1];
                bturn+=line[line.size()-1];
                line.pop_back();
            }
                turn++;
                aturn=0;
        }
        movescount++;
    }while(line.size()!=0);
    cout<<movescount<<" "<<a<<" "<<b<<endl;
}
int main(){
    int t=0; int n=0; cin>>t;
    for (int i=0; i<t; i++){
        cin>>n;
        vector <int> line;
        int temp;
        for (int j=0; j<n; j++){cin>>temp; line.push_back(temp);}
        execute(line, n);
    }
    return 0;
}
