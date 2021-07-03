#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ifstream cin("input.in");
    int t; cin>>t;
    for(int q=0; q<t; q++){
        cout<<"Case #"<<q+1<<": "<<endl;
        int n, m; cin>>n>>m; //num cities, tank capacity
        int c[n];
        for(int i=0; i<n; i++)
            cin>>c[i];
        int cPos=0; int cGas=m; int cost=0; bool p=true;
        while(cPos!=n-1){
            if(cPos+cGas<n-1){
                set<pair<int,int>> s;
                int k=1;
               // cout<<"cPos: "<<cPos<<endl<<"cGas: "<<cGas<<endl<<"k: "<<k<<endl;
                while(k<=cGas && cPos+k<n){
                    if(c[cPos+k]!=0){
                //        cout<<"inserting pair<int,int>("<<c[cPos+k]<<", "<<cPos+k<<")"<<endl;
                        s.insert(pair<int,int>(c[cPos+k], cPos+k));
                    }
                    k++;
                }
             //   cout<<"Now k is "<<k<<endl;
                if(s.size()==0){
                    cout<<-1<<endl; p=false; break;
                }
            //    cout<<"update cPos from "<<cPos<<" to ";
                cPos+=((s.begin()->second)-cPos);
              //  cout<<cPos<<endl;
             //   cout<<"update cGas from "<<cGas<<" to ";
                cGas-=((s.begin()->second)-cPos);
              //  cout<<cGas<<" to ";
                cGas=s.begin()->first + cGas;
               // cout<<cGas<<" to ";
                if(cGas>m){cGas=m;}
               // cout<<cGas<<endl;
                cost+=s.begin()->first;
            }
            else
                break;
        }
        if(p==true)
            cout<<cost<<endl;
    }
return 0;
}
