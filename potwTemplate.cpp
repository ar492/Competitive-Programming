#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

string input[10]={"input01.txt","input02.txt","input03.txt","input04.txt","input05.txt","input06.txt","input07.txt","input08.txt","input09.txt","input10.txt"};
string output[10]={"output01.txt","output02.txt","output03.txt","output04.txt","output05.txt","output06.txt","output07.txt","output08.txt","output09.txt","output10.txt"};

    ///UNIFORM from a to b inclusive
    /*
    srand(time(NULL));
    for(int i=0; i<10; i++){
        int r = a + (rand() % static_cast<int>(b - a + 1));
        cout<<r<<endl;
    }
    */
void genInput(){
    srand(time(NULL));
    for(int i=0; i<10; i++){
        ofstream fout(input[i]);
        int r = 1 + (rand() % static_cast<int>(10 - 1 + 1));
        fout<<r<<endl;
        for(int j=0; j<r; j++){
            int k=100 + (rand() % static_cast<int>(200 - 100 + 1));
            fout<<k<<" ";
        }
    }
}
void exePgrm(){
    for(int qq=0; qq<10; qq++){
        ifstream fin(input[qq]);
        ofstream fout(output[qq]);

    }


}
int main(){
    genInput();
    exePgrm();
    return 0;
}
