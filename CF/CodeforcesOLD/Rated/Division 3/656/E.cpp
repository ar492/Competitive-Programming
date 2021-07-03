#include <bits/stdc++.h>
#define pb push_back
#define INF (int)1e9
#define endl "\n"
typedef long long ll;
using namespace std;

struct node{
    int index; int ncns=0;
    bool operator<(const node& N) const
        {return ncns < N.ncns;}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("input.in");
    int t; cin>>t;
    for(int q=0; q<t; q++){
        int n,k; cin>>n>>k;
        /*cout<<"CASE WHERE n,k are "<<n<<" "<<k<<endl;*/
        vector<set<int>> a; //adj list
        vector<int> nCns; //nCns[i] is number of nodes connected to node i
        priority_queue<node> nodes;
        a.resize(n); nCns.resize(n);
        for(int i=0; i<n-1; i++){
            int u,v; cin>>u>>v;
            a[u-1].insert(v-1); a[v-1].insert(u-1);
            nCns[u-1]++; nCns[v-1]++;
        }
        int nmoves=0;
        for(int i=0; i<n; i++){
            node mynode;
            mynode.index=i; mynode.ncns=nCns[i];
            nodes.push(mynode);
            cout<<"Number of connections of node "<<i+1<<" is "<<nCns[i]<<endl;
        }
        cout<<"mynode.top() is "<<nodes.top().ncns<<endl;
        while(nodes.size()!=0){
            node cur=nodes.top(); nodes.pop();
            if(cur.ncns>=k){//number of connections of node i is >= k (min connections needed)
                vector<int> leaves;
                for(auto j=a[cur.index].begin(); j!=a[cur.index].end(); j++){//iterate through all connections of node i
                    if(nCns[*j]==1){//check if the node is a leaf (only 1 connection)
                        leaves.pb(*j);
                    }
                }
                /*cout<<"There are "<<leaves.size()<<" leaves for node (candidate) "<<i+1<<endl;*/
                if(leaves.size()>=k){//check if there are enough leaves to remove some
                    nmoves++;
                    /*cout<<"removing leaves: ";*/
                    for(int j=0; j<k; j++){//removal of exactly k leaves
                        a[cur.index].erase(leaves[j]);//removal of each leaf from the parent node
                       /* cout<<leaves[j]+1<<" ";*/
                    }/*cout<<endl;*/
                    nCns[cur.index]-=k; //reduce number of connections of parent node
                   /* cout<<"Number connections "<<i+1<<" is now "<<nCns[i]<<endl;*/
                    for(int j=0; j<k; j++){
                        nCns[leaves[j]]=0; //number of connections of leaf node = 0 because its deleted
                        a[leaves[j]].clear(); //erase the parent node that was connected to each leaf node from adj list
                    }
                    //i=-1;
                    /*cout<<endl;
                    cout<<"Number connections display: "<<endl;
                    for(int j=0; j<n; j++){
                        cout<<j+1<<": "<<nCns[j]<<endl;
                    }*/
                }
            }
        }
        cout<<nmoves<<endl;
    }

return 0;
}
