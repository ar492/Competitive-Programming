#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("card.in");

int ans=0;
bool check=true;
bool maxfind(int n, int x){
/*
if (n==7){
        cout<<n<<" <= "<<((x*(x+1))/2)+(x+1)*(x+2)<<endl;
        cout<<n<<" > "<<((x*(x+1))/2)+(x+1)*(x+2)<<endl;
}
*/
if (n<((x*(x+1))/2)+(x+1)*(x+2)){return false;}
else if (n>=((x*(x+1))/2)+(x+1)*(x+2)){return true;}

}
void execute(int n, int x){
if (n>=2){
    /*
for (int x=0; x<5; x++){
cout<<((x*(x+1))/2)+(x+1)*(x+2)<<" ";
}
cout<<endl;
//check=true;
*/
int i=0;
do{
i++;
}while (maxfind(n, i)!=false);
///cout<<"maxfind("<<n<<", "<<i<<") = false"<<endl;
int maximum=(((i-1)*(i))/2)+(i)*(i+1);
///cout<<"Maximum is "<<maximum<<endl;
n=n-maximum;
ans++;
///cout<<"execute("<<n<<", "<<0<<")"<<endl;
execute(n, 0);
}
///else {cout<<0<<endl;}
}

int main(){
int t;
fin>>t;
int n=0;
for (int i=0; i<t; i++){
    fin>>n;
    execute(n, 0);
    cout<<ans<<endl;
    ans=0;
}
//cout<<"MAXFIND 7 1 "<<maxfind(7, 1)<<endl;

return 0;
}
