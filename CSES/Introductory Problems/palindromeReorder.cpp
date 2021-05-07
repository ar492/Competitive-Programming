#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int ocnt=0; //oddcount
    char sp=' '; //special character which goes in the middle
    for(char c='A'; c<='Z'; c++){
        if(count(s.begin(), s.end(), c)%2==1){
            ocnt++; sp=c; s.erase(s.find(c), 1);
        }
    }
    if(ocnt>1){
        cout<<"NO SOLUTION"<<endl; return 0;
    }
    deque<char> d;
    if(ocnt==1) d.push_back(sp); //middle character
    bool chk=0; sort(s.begin(), s.end());
    for(int i=0; i<s.length(); i++){
        if(chk==0) d.push_back(s[i]);
        else if (chk==1) d.push_front(s[i]);
        chk=!chk;
    }
    for(char c:d) cout<<c;
return 0;
}
