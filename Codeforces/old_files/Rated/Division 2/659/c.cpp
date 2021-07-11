#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

struct P{
    int l; int r;
};
void exe(string a, string b){
    int n=a.length();
    for(int i=0; i<n; i++){
        if(a[i]>b[i]){
            cout<<-1<<endl; return;
        }
    }
    vector<P> ps;
    for(int i=0; i<n; i++){
        cout<<"i is "<<i<<endl;
        int k=i; bool chk=false;
        while(k<n && b[i]==b[k] && a[i]==a[k] && b[k]>a[k])
            {
                k++; chk=true;
              //  if(b[i]!=b[k]){k--; break;}
                cout<<"i,k is "<<i<<" "<<k<<endl;
                cout<<b[i]<<"=="<<b[k]<<endl;
            }
        if(chk==true){
            P p;
            p.l=i; p.r=k-1;
            ps.pb(p);
            i+=(p.r-p.l);
        }
    }

    for(int i=0; i<ps.size(); i++){
        cout<<ps[i].l<<" "<<ps[i].r<<endl;
    }
   cout<<ps.size()<<endl;

}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n; cin>>n;
        string a,b; cin>>a>>b;
        if(a.length()==1 && a[0]<b[0])
            cout<<"1"<<endl;
        else
            exe(a,b);
        cout<<endl;
    }
return 0;
}

