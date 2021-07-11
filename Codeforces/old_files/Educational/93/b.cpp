#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define INF (int)1e9
#define MOD (int)(1e9+7)
#define endl "\n"
typedef long long ll;
using namespace std;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int cnt=0; //alice goes first
        string s; cin>>s; int l=s.length();
        bool turn=0; //0 means alice
        while(count(s.begin(), s.end(), '1')>0){
            int li=-1; int ri=-1;
            int msize=0;
            for(int i=0; i<l; i++){
                int ic=i;
                while(s[i]=='1')
                    i++;
                if(s[ic]=='1'){
                    i--;
                   // cout<<"erase "<<ic<<", "<<i-ic+1<<endl;
                    //cout<<s<<endl;
                  // cout<<"i-ic+1 is "<<i-ic+1<<endl;

                    if(i-ic+1>msize){
                        msize=i-ic+1;
                        li=ic; ri=i;
                    }
                }
               // cout<<ic<<" to "<<i<<endl;
            }
           if(li!=-1 && ri!=-1){
                //cout<<"li,ri: "<<li<<" "<<ri<<endl;
                for(int i=li; i<=ri; i++)
                    s[i]='0';
               // if(li!=ri) s.erase(s.begin()+li, s.begin()+ri);
                //else s.erase(li);
                //cout<<s<<endl;
                if(!turn) cnt+=ri-li+1;
                turn=!turn;
           }
        }
        cout<<cnt<<endl;
    }
return 0;
}
