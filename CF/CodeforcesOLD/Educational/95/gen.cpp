#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ofstream cout("input.in");
    cout<<32<<endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                for(int l=0; l<2; l++){
                    for(int m=0; m<2; m++){
                        cout<<5<<endl<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<endl;
                    }
                }
            }
        }
    }
return 0;
}
