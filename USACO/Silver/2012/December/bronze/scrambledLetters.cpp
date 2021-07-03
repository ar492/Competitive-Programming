#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    set<string> names;
    string acnames[n];
    for(int i=0; i<n; i++){
        string s; cin>>s; sort(s.begin(), s.end()); names.insert(s); acnames[i]=s;
    }
    for(int i=0; i<n; i++){
        string cur=acnames[i];
        sort(cur.begin(), cur.end());
        names.erase(cur);
        reverse(cur.begin(), cur.end());
        for(auto it=names.begin(); it!=names.end(); it++){
            string s=*it;
            cout<<"s is "<<s<<endl;
            names.erase(s);
            sort(s.begin(), s.end());
            names.insert(s);
            cout<<"good at end"<<endl;
        }
        names.insert(cur);
        int lowest=(int)(distance(names.begin(), names.find(cur)));
        names.erase(cur);
        reverse(cur.begin(), cur.end());
        for(auto it=names.begin(); it!=names.end(); it++){
            string s=*it;
            names.erase(s);
            reverse(s.begin(), s.end());
            names.insert(s);
        }
        names.insert(cur);
        int highest=(int)(distance(names.begin(), names.find(cur)));
        names.erase(cur);
        sort(cur.begin(), cur.end());
        names.insert(cur);
        for(auto it=names.begin(); it!=names.end(); it++){
            string s=*it;
            names.erase(s);
            sort(s.begin(), s.end());
            names.insert(s);
        }
        cout<<highest<<" "<<lowest<<endl;
    }
return 0;
}
