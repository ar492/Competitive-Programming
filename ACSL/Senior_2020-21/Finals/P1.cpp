#include<bits/stdc++.h>
using namespace std;

map<char, int> mp={{'Q', 1}, {'R', 2}, {'B', 3}, {'P', 4}, {'N', 5}, {'K', 6}};
bool checks[8][8];
int pieces[8][8]; 

int dr[]={-1, -1, -1, 0, 0, 1, 1, 1}; // king
int dc[]={-1, 0, 1, -1, 1, -1, 0, 1};
bool is_valid(int row, int col){
       if(row<0 || col<0 || row>7 || col>7) return false;
       return true;
}
void add_piece(string pos){
       int row=8-stoi(string()+pos[2]);
       int col=pos[1]-'a';
       pieces[row][col]=mp[pos[0]];
}
void paths(int row, int col){
       if(pieces[row][col]==1){
              for(int r=row+1; r<8; r++){
                     if(pieces[r][col]){ checks[r][col]=1; break; }
                     else checks[r][col]=1;
              }
              for(int r=row-1; r>=0; r--){
                     if(pieces[r][col]){ checks[r][col]=1; break; }
                     else checks[r][col]=1;
              }
              for(int c=col+1; c<8; c++){
                     if(pieces[row][c]){ checks[row][c]=1; break; }
                     else checks[row][c]=1;
              }
              for(int c=col-1; c>=0; c--){
                     if(pieces[row][c]){ checks[row][c]=1; break; }
                     else checks[row][c]=1;
              }
              for(int r=row+1; r<8; r++){
                     int c=col+(r-row);
                     if(pieces[r][c]){ checks[r][c]=1; break; }
                     else checks[r][c]=1;
              }
              for(int r=row-1; r>=0; r--){
                     int c=col+(r-row);
                     if(pieces[r][c]){ checks[r][c]=1; break; }
                     else checks[r][c]=1;
              }
              for(int r=row+1; r<8; r++){
                     int c=col-(r-row);
                     if(pieces[r][c]){ checks[r][c]=1; break; }
                     else checks[r][c]=1;
              }
              for(int r=row-1; r>=0; r--){
                     int c=col-(r-row);
                     if(pieces[r][c]){ checks[r][c]=1; break; }
                     else checks[r][c]=1;
              }
       }
       else if(pieces[row][col]==2){
              for(int r=row+1; r<8; r++){
                     if(pieces[r][col]){ checks[r][col]=1; break; }
                     else checks[r][col]=1;
              }
              for(int r=row-1; r>=0; r--){
                     if(pieces[r][col]){ checks[r][col]=1; break; }
                     else checks[r][col]=1;
              }
              for(int c=col+1; c<8; c++){
                     if(pieces[row][c]){ checks[row][c]=1; break; }
                     else checks[row][c]=1;
              }
              for(int c=col-1; c>=0; c--){
                     if(pieces[row][c]){ checks[row][c]=1; break; }
                     else checks[row][c]=1;
              }
       }
       else if(pieces[row][col]==3){
              for(int r=row+1; r<8; r++){
                     for(int c=col+1; c<8; c++){
                            if(abs(c-r)!=abs(row-col)) continue;
                            if(pieces[r][c]){ checks[r][c]=1; break; }
                            else checks[r][c]=1;
                     }
              }
              for(int r=row-1; r>=0; r--){
                     for(int c=col+1; c<8; c++){
                            if(abs(c-r)!=abs(row-col)) continue;
                            if(pieces[r][c]){ checks[r][c]=1; break; }
                            else checks[r][c]=1;
                     }
              }
              for(int r=row+1; r<8; r++){
                     for(int c=col-1; c>=0; c--){
                            if(abs(c-r)!=abs(row-col)) continue;
                            if(pieces[r][c]){ checks[r][c]=1; break; }
                            else checks[r][c]=1;
                     }
              }
              for(int r=row-1; r>=0; r--){
                     for(int c=col-1; c>=0; c--){
                            if(abs(c-r)!=abs(row-col)) continue;
                            if(pieces[r][c]){ checks[r][c]=1; break; }
                            else checks[r][c]=1;
                     }
              }
       }
       else if(pieces[row][col]==4){
              if(is_valid(row-1, col-1)) checks[row-1][col-1]=1;
              if(is_valid(row-1, col+1)) checks[row-1][col+1]=1;
       }
       else if(pieces[row][col]==5)
              for(int i=0; i<8; i++)
                     for(int j=0; j<8; j++)
                            if(!(i==row && j==col) && ((abs(row-i)==1 && abs(col-j)==2) || ((abs(row-i)==2 && abs(col-j)==1)))) checks[i][j]=1;
}
string find_king_status(string s) {
       if(s.back()==' ') s.pop_back();
       for(int i=0; i<s.length(); i+=4){
              add_piece(s.substr(i, 3));
       }
       int rk, ck;
       for(int i=0; i<8; i++){
              for(int j=0; j<8; j++){
                     if(pieces[i][j]==6){
                            rk=i; ck=j; continue;
                     }
                     if(pieces[i][j]){
                            paths(i, j);
                     }
              }
       }
       int num_adj=0, num_oops_adj=0, num_adj_check=0;
       for(int k=0; k<8; k++){
              int rr=rk+dr[k];
              int cc=ck+dc[k];
              if(!is_valid(rr, cc)) continue;
              num_adj++;
              num_oops_adj+=(checks[rr][cc] || (pieces[rr][cc]>0));
              num_adj_check+=checks[rr][cc];
       }
       if(checks[rk][ck]){
              if(num_adj_check==num_adj) return "CHECKMATE";
              return "CHECK";
       }
       if((!checks[rk][ck]) && (num_oops_adj==num_adj)){
              return "STALEMATE";
       }
       return "SAFE";
}
int main(){
       cout<<find_king_status("Ba1 Rd3 Rg7 Qb3 Ke6")<<endl;
}