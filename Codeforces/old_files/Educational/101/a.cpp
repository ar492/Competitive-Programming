/// MISREAD THE PROBLEM
/// READ CAREFULLY
///only 2 parenthesis but i thought any amount
/*
int T; cin >> T;
    while(T--) {
        string S; cin >> S;
        if (sz(S) % 2) {
            cout << "NO" << nl; continue;
        }
        int L = 0, R = 0;
        trav(a, S) {
            if (a == '(') {
                L++; R++;
            } else if (a == ')') {
                L--; R--;
                if (R < 0) {
                    cout << "NO" << nl; goto done;
                }
                ckmax(L, 0);
            } else {
                L--; R++;
                ckmax(L, 0);
            }
        }
        cout << (L==0?"YES":"NO") << nl;
        done:;
    }
*/

/// geothermal - how to do if multiple parenthesis and question marks

#include <bits/stdc++.h>
#define deb(x) cout<<#x<<" "<<x<<endl;
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        stack<char> v;
        if(count(s.begin(), s.end(), ')')>count(s.begin(), s.end(), '(')){
            for(char c:s){
                if(v.empty()){ //cout<<"push"<<endl;
                v.push(c); }
                else if(c=='?' && v.top()=='('){ //cout<<"push"<<endl;
                v.push(c); }
                else if(c=='?' && v.top()==')'){ //cout<<"push"<<endl;
                v.push(c); }
                else if(c==')' && v.top()!=')'){ //cout<<"pop"<<endl;
                v.pop(); }
                else if(c=='?' && v.top()=='?'){ //cout<<"push"<<endl;
                v.push(c); }
                else { //cout<<"push"<<endl;
                v.push(c); }
            }
            cout<<(v.empty() ? "YES": "NO")<<endl;
        }
        else{
            stack<char> v;
            for(char c:s){
                if(v.empty()) v.push(c);
                else if(c=='?' && v.top()=='(')v.pop();
                else if(c=='?' && v.top()==')') v.push(c);
                else if(c==')' && v.top()!=')')v.pop();
                else if(c=='?' && v.top()=='?')v.pop();
                else  v.push(c);
            }
            cout<<(v.empty() ? "YES": "NO")<<endl;
        }
    }
return 0;
}
/*
1
((?)))

1
((?))??)
*/
