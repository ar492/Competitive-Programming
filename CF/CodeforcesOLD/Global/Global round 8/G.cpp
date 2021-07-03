///not working
#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

int main(){
int n,m; cin>>n>>m;
char grid[n][m];
for(int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        char temp; cin>>temp; grid[i][j]=temp;
    }
}
cout<<n<<" "<<m<<endl;
ll counter=0;
counter+=(n*m)/2; ///photos with only removal, no moves
for(int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        cout<<grid[i][j]<<" ";
    }
    cout<<endl;
}
cout<<"_________________________"<<endl;

for(int q=0; q<n; q++){
    for (int r=0; r<m; r++){
        bool check=false;
        int i=q; int j=r;
        char c1=grid[q][r];
        char grid2[n][m];
        for(int z=0; z<n; z++){for(int x=0; x<m; x++){grid2[z][x]=grid[z][x];}}
        if(grid2[q][r]=='L'){grid2[q][r]=' '; grid2[q][r+1]=' ';}
        else if(grid2[q][r]=='R'){grid2[q][r-1]=' '; grid2[q][r]=' ';}
        else if(grid2[q][r]=='U'){grid2[q][r]=' '; grid2[q+1][r]=' ';}
        else if(grid2[q][r]=='D'){grid2[q][r]=' '; grid2[q-1][r]=' ';}
        while(check==false){
            bool check2=false;
            if(j-1>=0){
                if(grid2[i][j-1]=='R'){
                    grid2[i][j]='R';
                    grid2[i][j-1]='L';
                    grid2[i][j-2]=' ';
                    j-=2;
                    counter++;
                    for(int y=0; y<n; y++){
                    for (int u=0; u<m; u++){
                        cout<<grid2[y][u]<<" ";
                    }
                    cout<<endl;
                    }cout<<endl;
                }
                else{check2=true;}
            }
            if(j+1<m){
                if(grid2[i][j+1]=='L'){
                    grid2[i][j]='L';
                    grid2[i][j+1]='R';
                    grid2[i][j+2]=' ';
                    j+=2;
                    counter++;
                                        for(int y=0; y<n; y++){
                    for (int u=0; u<m; u++){
                        cout<<grid2[y][u]<<" ";
                    }
                    cout<<endl;
                    }
                    cout<<endl;
                }
                else{check2=true;}
            }
            if(i-1>=0){
                if(grid2[i-1][j]=='D'){
                    grid2[i][j]='D';
                    grid2[i-1][j]='U';
                    grid2[i-2][j]=' ';
                    i-=2;
                    counter++;
                                        for(int y=0; y<n; y++){
                    for (int u=0; u<m; u++){
                        cout<<grid2[y][u]<<" ";
                    }
                    cout<<endl;
                    }
                    cout<<endl;
                }
                else{check2=true;}
            }
            if(i+1<n){
                if(grid2[i+1][j]=='U'){
                    i+=2;
                    grid2[i][j]='U';
                    grid2[i+1][j]='D';
                    grid2[i+2][j]=' ';
                    counter++;
                                        for(int y=0; y<n; y++){
                    for (int u=0; u<m; u++){
                        cout<<grid2[y][u]<<" ";
                    }
                    cout<<endl;
                    }
                    cout<<endl;
                }
                else{check2=true;}
            }
            if(check2==true){check=true;}
        }
    }

}
cout<<counter<<endl;
/*
for(int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        if(grid[i][j+1]==)
    }
}
*/
return 0;
}
