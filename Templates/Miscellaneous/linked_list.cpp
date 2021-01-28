#include<bits/stdc++.h>
using namespace std;

struct node{
        int val; node *to;
        void link(node &b){ to=&b; }
        node next(){ return(*to); }
};

int main(){

        return 0;
}
