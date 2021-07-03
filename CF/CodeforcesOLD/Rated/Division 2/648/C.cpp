#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
/*
void RshiftB(vector <int> & b){
int temp=b[0];
b.erase(b.begin());
b.push_back(temp);
}

int countcommon(vector <int> a, vector <int> b){
int counter=0;
for (int i=0; i<a.size(); i++){if (a[i]==b[i]){counter++;}}
return counter;
}
int main(){
int n;
fin>>n;
vector <int> a;
vector <int> b;
for (int i=0; i<n; i++){int temp; fin>>temp; a.push_back(temp);}
for (int i=0; i<n; i++){int temp; fin>>temp; b.push_back(temp);}
for (int i=0; i<n; i++){cout<<b[i]<<" ";}
cout<<endl;
int maximum=0;
maximum=max(countcommon(a, b), maximum);
for (int i=0; i<n; i++){
    RshiftB(b);
    maximum=max(countcommon(a, b), maximum);
}
RshiftB(b);
for (int i=0; i<n; i++){cout<<b[i]<<" ";}
cout<<endl;
cout<<maximum<<endl;
return 0;
}
*/
int main(){
int n;
fin>>n;
vector <int> a;
vector <int> b;
vector <int> indices;
for (int i=0; i<n; i++){int temp; fin>>temp; a.push_back(temp);}
for (int i=0; i<n; i++){int temp; fin>>temp; b.push_back(temp);}
int index;
for (int j=0; j<n; j++){
for (int i=0; i<n; i++){
    if(a[i]==b[j]){indices.push_back(i); break;}
}
}
int maximum=0;
int tempmax=0;
bool visited[n+1];
for (int i=0; i<=n; i++){visited[i]=0;}
for (int j=0; j<indices.size(); j++){
for (int i=0; i<n; i++){
    if(visited[i]==0){
    cout<<"i: "<<i<<" "<<"is b["<<i%n<<"] = a["<<((i+indices[j])%n)<<"]"<<endl;
   if(b[(i%n)]==a[((i+indices[j])%n)]){visited[b[(i%n)]]=1;cout<<"yes"<<endl; tempmax++;}
    }
}
maximum=max(tempmax, maximum);
tempmax=0;
}
cout<<maximum<<endl;


}
