#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
int h; char trash; int m; int minforward;
cin>>h>>trash>>m>>minforward;
cout<<h<<" "<<trash<<" "<<m<<endl;
int acmin=(h*60+m+minforward)%60;
int achr=((h*60+m+minforward)/60)%24;
string a, b;
if(acmin==0){a="00";}
if(achr==0){b="00";}
if(acmin!=0 && acmin<10){a='0'+to_string(acmin);}
if(achr!=0 && achr<10){b='0'+to_string(achr);}
if(acmin>=10){a=to_string(acmin);}
if(achr>=10){b=to_string(achr);}
cout<<b<<":"<<a<<endl;
return 0;
}
