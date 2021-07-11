#include <iostream>
#include <fstream>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
    ifstream cin("input.in");
    int t; cin>>t;
    for(int q=0; q<t; q++){
        ll a,b; cin>>a>>b;
        //cout<<"((double)max(a,b))/((double)min(a,b)): "<<((double)max(a,b))/((double)min(a,b))<<endl;
        //cout<<"(ll)(max(a,b)/min(a,b)): "<<(ll)(max(a,b)/min(a,b))<<endl;
        if(a==b)
            cout<<0<<endl;
        else if(((double)max(a,b))/((double)min(a,b))!=(ll)(max(a,b)/min(a,b)))
            cout<<-1<<endl;
        else{
            bool chk=false;
            ll res=max(a,b)/min(a,b);
            ll i=0;
            while(pow(2,i)!=res && pow(2,i)<=res){
                i++;
                if(pow(2,i)==res)
                    chk=true;
            }
            //cout<<"i, chk is "<<i<<" "<<chk<<endl;
            if(chk==false)
                cout<<-1<<endl;
            else{
                if(i<3)
                    cout<<1<<endl;
                else if (i%3==0)
                    cout<<i/3<<endl;
                else if (i%3==1 || i%3==2)
                    cout<<i/3+1<<endl;
            }
        }
    }
return 0;
}
