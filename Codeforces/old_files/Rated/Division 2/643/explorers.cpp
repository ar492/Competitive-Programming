#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

void Print(vector<int> inexperiences){
            cout<<"-------VECTOR DISP START ---------------"<<endl;
            for(int j=0; j<inexperiences.size(); j++){
                cout<<inexperiences[j]<<" ";
            }cout<<endl;
            cout<<"-------VECTOR DISP END ---------------"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n; cin>>n;
        vector<int> inexperiences;
        for(int i=0; i<n; i++){
            int temp; cin>>temp; inexperiences.pb(temp);
        }
        sort(inexperiences.begin(), inexperiences.end());
        int counter=0;
        for(int i=0; i<inexperiences.size(); i++){
            if(inexperiences[i]<=i+1){
               // cout<<"NEED TO ERASE until and including inexperiences["<<i<<"] = "<<inexperiences[i]<<endl;
                //cout<<"BEFORE ERASE"<<endl;Print(inexperiences);
                inexperiences.erase(inexperiences.begin(), inexperiences.begin()+i+1);
                //cout<<"AFTER ERASE"<<endl;Print(inexperiences);
                i=-1;
                counter++;
            }///1 1 3
        }
        cout<<counter<<endl;
    }

return 0;
}
