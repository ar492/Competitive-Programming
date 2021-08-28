#include<bits/stdc++.h>
using namespace std;

struct rectangle{
	int x1, y1, x2, y2;
	bool inside(int x, int y){
		return(x>=x1 && x<=x2 && y>=y1 && y<=y2);
	}
};

istream& operator>>(istream &in, rectangle &r) {
	return in>>r.x1>>r.y1>>r.x2>>r.y2;
}

void yes(){cout<<"YES"<<endl; exit(0);}
void no(){cout<<"NO"<<endl; exit(0);}

signed main(){

	rectangle white, black1, black2;
	cin>>white>>black1>>black2;
	int sum=0, cnt1=0, cnt2=0;
	for(int x:{white.x1, white.x2}){
		for(int y:{white.y1, white.y2}){
			sum+=(black1.inside(x, y) || (black2.inside(x, y)));
			cnt1+=black1.inside(x, y); cnt2+=black2.inside(x, y);
		}
	}
	if(cnt1>=4 || cnt2>=4) no(); // if white is completely engulfed in a black
	if(sum!=4) yes(); // if a corner of white is not occupied by black
	int lb, ub;
	if((black1.inside(white.x1, white.y1)+black1.inside(white.x1, white.y2))%2==0){ // blacks are vertical, find vert gap
		lb=black1.x2, ub=black2.x1;
		if(!black1.inside(white.x1, white.y1)) ub=black1.x1, lb=black2.x2;	
	}
	else{
		lb=black1.y2, ub=black2.y1;
		if(!black1.inside(white.x1, white.y1)) ub=black1.y1, lb=black2.y2;	
	}
	if(lb<ub) yes(); no();
}
