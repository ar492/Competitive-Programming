#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;

struct query{
int a; int b;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    int q; cin>>q;
    vector<int> haylocs;
    for(int i=0; i<n; i++){
        int temp; cin>>temp;
        haylocs.pb(temp);
    }
    sort(haylocs.begin(), haylocs.end());
    vector<query> queries;
    for(int i=0; i<q; i++){
        query myQ;
        int t1, t2; cin>>t1>>t2;
        myQ.a=t1; myQ.b=t2;
        queries.pb(myQ);
    }
    for(int i=0; i<queries.size(); i++){
        vector<int>::iterator low, high;
        low=lower_bound(haylocs.begin(), haylocs.end(), queries[i].a);
        high=upper_bound(haylocs.begin(), haylocs.end(), queries[i].b);
        cout<<(high-haylocs.begin())-(low-haylocs.begin())<<endl;
    }
 /*
    for each query, we are binary
    searching for the location of the lower bound
    and upperbound of the query, then computing upper-lower+1
    to see how many haybales are in the query
    */
return 0;
}
