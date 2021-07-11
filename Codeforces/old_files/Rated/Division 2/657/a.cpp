#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

string qr(string s){
    replace(s.begin(), s.end(), '?', 'd'); return s;
}
int Cnt(string s){
    int c=0;
    for (int i=0; i<=s.length()-7; i++) {
        if (s.substr(i, 7)=="abacaba")
            c++;
    }
    return c;
}

void exe(string s){
    int counter=0; string tofind="abacaba"; string ans="";
    vector<int> does; vector<int> could;
        for(int i=0; i<=s.length()-7; i++){//start searching from the ith position
            int j=i;
            while(j<i+tofind.length()){
                if(tofind[j-i]==s[j] || s[j]=='?'){
                    if(j==i+tofind.length()-1){
                        if(s.substr(j-6, 7).find('?')!=-1)
                            could.pb(j);
                        else
                            does.pb(j);
                        counter++;
                    }
                }
                else
                    break;
                j++;
            }
        }

    //cout<<"does.size() is "<<does.size()<<": ";
    //for(int i=0; i<does.size(); i++){cout<<does[i]<<" ";}cout<<endl;
    //cout<<"could.size() is "<<could.size()<<": ";
    //for(int i=0; i<could.size(); i++){cout<<could[i]<<" ";}cout<<endl;

    if(does.size()+could.size()==0 || does.size()>1)
        cout<<"No"<<endl;
    else if (does.size()==1 || (does.size()==0 && could.size()>=1)){
        if(does.size()==1)
            cout<<"Yes"<<endl<<qr(s)<<endl;

        else if (could.size()>=1){
            int i=0;
            while(i<could.size()){
                string scopy=s.substr(0, s.length()-could[0]-1)+tofind+s.substr(s.length()-could[0]+6, could[0]-6);
                if(Cnt(scopy)==1){
                    cout<<"Yes"<<endl<<qr(scopy)<<endl;
                    return;
                }
                i++;
            }
            cout<<"No"<<endl;
           // cout<<string()+s.substr(0, s.length()-could[0]-1)+"abacaba"+s.substr(s.length()-could[0]+6, could[0]-6)<<endl;
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n; string s;
        cin>>n>>s;
        //cout<<endl;
        exe(s);
        //cout<<endl;
    }
return 0;
}
