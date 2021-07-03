#include <bits/stdc++.h>
using namespace std;

void setup(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
}

int main(){
    setup();
    int N,K; cin>>N>>K;
    int cil=0; //num chars in line
    for(int i=0; i<N; i++){
        //cout<<cil;
        string s;
        cin>>s;
        if(cil==0){
            cout<<s;
            cil+=s.length();
        }
        else{
            if(cil+s.length()<=K){
                cout<<" "<<s;
                cil+=(s.length());

            }
            else{
                cout<<endl;
                cout<<s;
                cil=s.length();
            }
        }
    }
    cout<<endl;

return 0;
}
