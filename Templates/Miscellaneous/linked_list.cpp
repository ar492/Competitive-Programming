#include<bits/stdc++.h>
using namespace std;

struct node{
        int val; node *to=NULL;
        void link(node &b){ to=&b; }
        node next(){ return (*to); }
};

int main(){
	node a; a.val=1;
	if(a.to==NULL) cout<<"no next"<<endl;
        node b;
        b.val=4;
        a.link(b);
        cout<<a.next().val<<endl;
        return 0;
}
