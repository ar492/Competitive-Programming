#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
ifstream fin("input.in");

int main(){
int t; fin>>t;
for (int w=0; w<t; w++){
    int n, x; fin>>n>>x;
    vector <int> arr;
    int accum=0;
    for (int k=0; k<n; k++){
        int temp; fin>>temp; int temp2=temp%x; arr.pb(temp2); accum+=temp2;
    }
    if(accum%x!=0){cout<<"cout1 "<<n<<endl;}
    else{
    int r=arr.size()-1;
    int l=0;
    bool check=false;
    do{
        if(arr[r]%x!=0){
            int tempaccum=0;
            for (int i=arr.size()-1; i>=r; i--){
                tempaccum+=arr[i];
            }
            if(tempaccum%x!=0){cout<<"cout2 "<<n-(n-r)<<endl; check=true;}
            else{r--;}
        }
        if(arr[r]%x==0){r--;}
        if(arr[l]%x!=0){
            int tempaccum=0;
            for(int i=0; i<=l; i++){
                tempaccum+=arr[i];
            }
            if(tempaccum%x!=0){cout<<"cout3 "<<n-l-1<<endl; check=true;}
            else{r--;}
        }
        if(arr[l]%x==0){l++;}
        if(l>r){cout<<"-1"<<endl; check=true;}
    }while(check==false);

    }


}

return 0;
}
