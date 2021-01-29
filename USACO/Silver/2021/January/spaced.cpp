#include<bits/stdc++.h>
using namespace std;

int g[1000][1000], hans, vans, n;

int rowSpace(int row, int sum=0){ for(int i=1; i<n; i+=2) sum+=g[row][i]; return sum; } //space to start the row
int rowNoSpace(int row, int sum=0){ for(int i=0; i<n; i+=2) sum+=g[row][i]; return sum; } // C to start the row
int colSpace(int col, int sum=0){ for(int i=0; i<n; i+=2) sum+=g[i][col]; return sum; } // space to start the column
int colNoSpace(int col, int sum=0){ for(int i=1; i<n; i+=2) sum+=g[i][col]; return sum; } // C to start the column

int main(){
	cin>>n;
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) cin>>g[i][j];
        for(int i=0; i<n; i++){
                hans+=max(rowSpace(i), rowNoSpace(i));
                vans+=max(colSpace(i), colNoSpace(i));
        }
        cout<<max(hans, vans)<<endl;
}
