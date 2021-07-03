#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

///MISC MI
///MIAMI MI
///the answer to this case is 0, because the state is the same (MI) in both
///.. and the pairs have to originate from distinct states.
/* why does this not work, and below one works
int main(){
    ifstream cin("citystate.in"); ofstream cout("citystate.out");
    set<string> sa; //state, abbreviation
    int n; cin>>n;
    int cnt=0;
    for(int i=0; i<n; i++){
        string a,b; cin>>a>>b;
        if(string()+b!=string()+a[0]+a[1])
            cnt+=sa.count(string()+b+a[0]+a[1]);
       // cout<<"counting : "<<(string()+b+a[0]+a[1])<<" is "<<sa.count(string()+b+a[0]+a[1])<<endl;
        sa.insert(string()+a[0]+a[1]+b);
    }
    cout<<cnt<<endl;
return 0;
}
*/

int main(){
    ifstream cin("citystate.in"); ofstream cout("citystate.out");
    multiset<string> sa; //state, abbreviation
    ll n; cin>>n;
    for(int i=0; i<n; i++){
        string a,b; cin>>a>>b;
        sa.insert(string()+a[0]+a[1]+b);
    }
    int cnt=0;
    for(auto it=sa.begin(); it!=sa.end(); it++){
        //cout<<"*it is "<<*it<<endl;
        string s=*it;
        s=string()+s[2]+s[3]+s[0]+s[1];
        //cout<<"s is "<<s<<endl;
        if(s!=*it)
            cnt+=sa.count(s);

    }
    cout<<cnt/(ll(2))<<endl;


return 0;
}


