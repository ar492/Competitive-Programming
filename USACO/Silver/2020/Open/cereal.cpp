/*
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100001

int N,M;
int f[MAXN];
int s[MAXN];
int occ[MAXN];

int ans[MAXN];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out","w",stdout);
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> f[i] >> s[i];
	int cnt = 0;
	for(int i=N-1;i>=0;i--)
	{
		int j = i;
		int pos = f[i];
		while(1)
		{
			if(occ[pos] == 0)
			{
				occ[pos] = j;
				cnt++;
				break;
			}
			else if(occ[pos] < j)
				break;
			else
			{
				int k = occ[pos];
				occ[pos] = j;
				if(pos == s[k])
					break;
				j = k;
				pos = s[k];
			}
		}
		ans[i] = cnt;
	}
	for(int i=0;i<N;i++)
		cout << ans[i] << '\n';
}*/

#include <bits/stdc++.h>
using namespace std;

const int sz = (int)1e5 + 1;
int f[sz], s[sz], cereals[sz], cnt;
stack<int> ans;
//0 index everything
int prev = 0;
int vis[sz];
void recurse(int cow) { //only called if a prev(above) one took what i took before
    //there is conflict
    int who = cereals[s[cow]];
    cereals[s[cow]] = cow;
    if(who > cow) { //taking it from a future cow
        recurse(who);
    } else if(who == 0) { //no more stealing
        cnt++;
    }
    //cow leaves empty handed
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    int n, m;
    cin >> n >> m; //cows are 0 to n-1 numbering
    for(int i = 1; i <= n; i++) cin >> f[i] >> s[i];
    for(int i = n; i >= 1; i--) { //add ith cow
        int who = cereals[f[i]];
        cereals[f[i]] = i;
        if(who == 0) { //if added cow has no conflict
            cnt++;
        } else {
            recurse(who);
        }
        ans.push(cnt);
    }
    while(!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}
