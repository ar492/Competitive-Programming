#include <bits/stdc++.h>
using namespace std;

vector<int> adj[20];
int pathlength, ans, cnt;

void dfs(int node, string path)
{
       if (path.length() == pathlength + 1)
              cnt++, ans += stoi(path);
       else
              for (int i : adj[node])
                     if (!count(path.begin(), path.end(), '0' + i))
                            dfs(i, path + to_string(i));
}

int sumPathsOfLengthN(int num, string edges)
{
       pathlength = num;
       edges = " " + edges;
       for (int i = 0; i < edges.size() - 2; i++)
              if (edges[i] == ' ')
                     adj[edges[i + 1] - '0'].push_back(edges[i + 2] - '0');
       for (int i = 1; i <= 9; i++)
              if (adj[i].size())
                     dfs(i, to_string(i));
       return ans;
}

int main()
{
       int n = 2;
       cout << sumPathsOfLengthN(n, "12 23 34 41 31") << endl;
       cout << cnt << endl;
}