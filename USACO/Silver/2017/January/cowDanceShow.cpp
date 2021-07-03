#include<bits/stdc++.h>
using namespace std;


int n, t; // n is number of cows, t is max time allowed for all cows to finish dancing
int d[10000];
bool ok (int k) { // k is stage size
    priority_queue<int, vector<int>, greater<int>> stage;
    int index = 0;
    while (stage.size() < k) {
        stage.push (d[index]);
        index++;
    }
    while (index < n) {
        int insertion = d[index] + stage.top();
        stage.pop();
        stage.push (insertion);
        index++;
    }
    for (int i = 0; i < k - 1; i++)
        stage.pop();
    return (stage.top() <= t);
}
int main() {
    ifstream cin ("cowdance.in");
    ofstream cout ("cowdance.out");
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    int l = 1, r = n, ans;
    while (l <= r) {
        int k = (l + r) / 2;
        if (ok (k)) {
            ans = k;
            r = k - 1;
        }
        else l = k + 1;
    }
    cout << ans << endl;
    return 0;
}
