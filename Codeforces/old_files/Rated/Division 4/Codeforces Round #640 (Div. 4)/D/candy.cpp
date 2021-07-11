#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("candy.in");
void print(vector <int> temp){
   /// for (int i=0; i<temp.size(); i++){cout<<temp[i]<<" ";}
    ///cout<<endl;
}
void execute(vector <int> line, int n){
int turn=0; int movescount=0;
int a=0; int b=0;
int aturn=0; int bturn=0;
    print(line);
    do{
        if (turn%2==0){///Alice's turn
               /// cout<<"before alice"<<endl;
                print(line);
            if (b==0){a+=line[0]; aturn=line[0]; line.erase(line.begin());}
            else if (b!=0){
                while(aturn<=bturn && line.size()!=0){
              ///      cout<<"bturn = "<<bturn<<", aturn = "<<aturn<<endl;
                    a+=line[0];
                    aturn+=line[0];
                    line.erase(line.begin());
                }
                /*
                    cout<<"bturn = "<<bturn<<", aturn = "<<aturn<<endl;
                    a+=line[0];
                    aturn+=line[0];
                    line.erase(line.begin());
                    bturn=0;
                    cout<<"after alice"<<endl;
                    print(line);
                    */
                    bturn=0;
            }
            turn++;
        }
        else if (turn%2==1){///Bob's turn
            ///    cout<<"before bob"<<endl;
                print(line);
            int i=0;
            while(bturn<=aturn && line.size()!=0){
              ///  cout<<"bturn = "<<bturn<<", aturn = "<<aturn<<endl;
                b+=line[line.size()-1];
                bturn+=line[line.size()-1];
                line.pop_back();
            }
            /*
                cout<<"bturn = "<<bturn<<", aturn = "<<aturn<<endl;
                b+=line[line.size()-1];
                bturn+=line[line.size()-1];
                line.pop_back();
                aturn=0;
                cout<<"after bob"<<endl;
                print(line);
                */
                turn++;
                aturn=0;
        }
        movescount++;
    }while(line.size()!=0);
    cout<<"answer incoming"<<endl;
    cout<<movescount<<" "<<a<<" "<<b<<endl;
}
int main(){
int t=0;
int n=0;
fin>>t;
for (int i=0; i<t; i++){
    fin>>n;
    vector <int> line;
    int temp;
    for (int j=0; j<n; j++){fin>>temp; line.push_back(temp);}
   /// cout<<n<<endl;
    ///for (int j=0; j<n; j++){cout<<line[j]<<" ";}
    ///cout<<endl;
    execute(line, n);


}
return 0;
}
