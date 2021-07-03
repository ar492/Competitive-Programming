#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

const int sz=1001;
bool stopped[sz];
int answer[sz];
pair<int, int> pos[sz];

struct col{
    int fault;
    int affected;
    int time;
    int x;
    int y;
    bool valid;
};

struct cow{
    char dir;
    int x;
    int y;
};

int n;
int locations[sz];
int stops[sz];
cow input[sz];
vector <col> collisions;

bool cmp(col a, col b){
    return a.time<b.time;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    //for each collision, keep track of whos fault it was, and who got affected
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>input[i].dir>>input[i].x>>input[i].y;
    }
    //fill(stopped, stopped+1000, -1);
    for(int i=0; i<n; i++){ // label 1
        pos[i].x=input[i].x;
        pos[i].y=input[i].y;
        for(int j=i+1; j<n; j++){ // label 2
            char d1=input[i].dir; char d2=input[j].dir;
            int x1=input[i].x; int y1=input[i].y;
            int x2=input[j].x; int y2=input[j].y;
            int ii=i;
            int jj=j;
            if(d1=='N' && d2=='E'){
                swap(d1, d2);
                swap(x1, x2);
                swap(y1, y2);
                swap(ii, jj);
            }
            cout<<"1(i="<<ii+1<<"): "<<d1<<" "<<x1<<" "<<y1<<endl;
            cout<<"2(j="<<jj+1<<"): "<<d2<<" "<<x2<<" "<<y2<<endl;
            if(d1=='E' && d2=='N'){
                if(x1<x2){
                    if(y2<y1 && x2-x1>y1-y2){// i collides with j
                        //stopped[i]=x2; //the x coordinate where it stops
                        cout<<"fault is "<<jj<<endl;
                        collisions.push_back({jj, ii, x2-x1, x2, y1, 1});
                    }
                    else if(y2<y1 && x2-x1<y1-y2){// j collides with i
                        //stopped[j]=y1;
                        cout<<"fault is "<<ii<<endl;
                        collisions.push_back({ii, jj, y1-y2, x2, y1, 1});
                        //cout<<"i's fault "<<endl;
                    }
                }
            }
            cout<<endl;
        }
    }
    sort(collisions.begin(), collisions.end(), cmp);
    for(auto i:collisions){
        cout<<"fault: "<<i.fault+1<<", affected: "<<i.affected+1<<", time: "<<i.time<<", location: "<<i.x<<" "<<i.y<<endl;
    }
    cout<<"doing it "<<endl;
    for(int j=0; j<collisions.size(); j++){
        col i=collisions[j];
        cout<<"fault: "<<i.fault+1<<", affected: "<<i.affected+1<<", time: "<<i.time<<", location: "<<i.x<<" "<<i.y<<endl;
        cout<<"stopped["<<i.affected+1<<"] is "<<stopped[i.affected]<<endl;
        if(stopped[i.affected]){ collisions[j].valid=false; cout<<"not valid "<<endl; }
        else if(stopped[i.fault]){
            if(pos[i.fault].x>pos[i.affected].x && pos[i.fault].y>pos[i.affected].y){
                pos[i.affected]={i.x, i.y}; cout<<"special case 1"<<endl;
            }
            else collisions[j].valid=false;
        }
        else pos[i.affected]={i.x, i.y};
        stopped[i.affected]=true;
    }

    cout<<"again:::"<<endl;
    for(auto i:collisions){
        if(i.valid==1){
            cout<<"fault: "<<i.fault+1<<", affected: "<<i.affected+1<<", time: "<<i.time<<", location: "<<i.x<<" "<<i.y<<endl;
            //answer[i.fault]+=answer[i.affected];
           // cout<<"answer["<<i.fault+1<<"] += answer["<<i.affected+1<<"]"<<endl;
           // if(answer[i.affected]==0) answer[i.fault]++;
            answer[i.fault]+=answer[i.affected]+1;
           // cout<<"answer["<<i.fault+1<<"] is now "<<answer[i.fault]<<endl;
        }
    }
    for(int i=0; i<n; i++){
        cout<<answer[i]<<endl;
    }
return 0;
}
/*
4
E 0 1
N 2 0
E 3 2
N 6 0
*/
