#include <bits/stdc++.h>
using namespace std;

const int sz=(int)2e5+1;
int a[sz], ans[sz], n;
vector<bool> v(sz); //visited

void cyclefind (int index) {
    vector<int> cycle;
    int c = index; cycle.push_back (c);
    while (!v[c]) {
        v[c] = 1; c = a[c];
        cycle.push_back (c);
    }
    if (c == index) { //the node(index) is in a cycle
        for(int i : cycle) ans[i] = cycle.size() - 1;
        return;
    }
    for (int i = 0; i < cycle.size(); i++) {
        if (cycle[i] == cycle.back()) {
            if (ans[cycle[i]] == 0) //cycle hasnt been processed yet
                for (int j = i; j < cycle.size(); j++)
                    ans[cycle[j]] = cycle.size() - i - 1;
            for (int j = 0; j < i; j++) //the stuff outside the cycle
                ans[cycle[j]] = ans[cycle[i]] + (i - j);//dist to cycle + cycle size
            return;
        }
    }
}
int main() {
    cin.tie (0)->sync_with_stdio (0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        if (ans[i] == 0) //not processed yet
            cyclefind (i);

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
//each connected cmp is done in O(cc.size) .. meaning each cc is done individually and when a cc is started, its done right after
