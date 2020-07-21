#include <bits/stdc++.h>
using namespace std;

string input[10]={"input01.txt","input02.txt","input03.txt","input04.txt","input05.txt","input06.txt","input07.txt","input08.txt","input09.txt","input10.txt"};
string output[10]={"output01.txt","output02.txt","output03.txt","output04.txt","output05.txt","output06.txt","output07.txt","output08.txt","output09.txt","output10.txt"};

int randAtoB(int a, int b){///Uniform distribution
    return(((double) rand() / (RAND_MAX+1)) * (b-a+1) + a);
}

void genInput(){
    for(int i=0; i<10; i++){
        ofstream fout(input[i]);
        int r=randAtoB(1, 10); fout<<r<<endl;
        for(int j=0; j<r; j++)
            if(j!=r-1)
                fout<<randAtoB(1, 10)<<" ";
            else
                fout<<randAtoB(1, 10)<<endl;
    }
}
void exePgrm(){
    for(int qq=0; qq<10; qq++){
        ifstream fin(input[qq]);
        ofstream fout(output[qq]);
        int n; fin>>n;
        int accum=0;
        for(int i=0; i<n; i++){
            int k; fin>>k; accum+=k;
        }
        fout<<accum<<endl;
    }
}
int main(){
    srand(time(NULL));
    genInput();
    exePgrm();

    return 0;
}
