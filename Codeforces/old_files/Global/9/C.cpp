#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            int temp; cin>>temp; a[i]=temp;
        }
        bool check=false;
        bool check2=false;
        for(int i=0; i<n-1; i++){
            if(a[i]<a[i+1])
                check=true;
            if(a[i]>a[i+1])
                check2=true;
        }

        if(check==false)
            cout<<"NO"<<endl;
        else if (check2==false)
            cout<<"YES"<<endl;
        else{
            bool check3=true;
            while(check3==true && a.size()!=1){
                vector<int> tempa=a;
                for(int i=0; i<a.size()-2; i++){
                    if(a[i]<a[i+1] && a[i+1]>a[i+2] && a[i]<a[i+2]){
                        a.erase(a.begin()+i+1);
                        i=0;
                    }
                }
                for(int i=0; i<a.size()-1; i++){
                    if(a[i]<a[i+1]){
                         a.erase(a.begin()+i);
                         i=0;
                    }
                }
                if(tempa==a || a.size()==1){check3=false; break;}
            }
            if(a.size()==1)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        /*
            cout<<"START ENDD DISP"<<endl;
            for(int i=0; i<a.size(); i++){
                cout<<a[i]<<" ";
            }cout<<endl;
            cout<<"END END DISP"<<endl;
            */
        }
    return 0;
}
