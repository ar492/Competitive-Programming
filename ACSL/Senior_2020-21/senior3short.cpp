#include <bits/stdc++.h>
using namespace std;

const int sz = 200;
bool vis[sz][sz];
int rows, cols, num, ans, a[sz][sz][sz];

void recurse(int r, int c)
{
       if (vis[r][c])
              return;
       vis[r][c] = 1;
       int mn = sz;
       for (int i = 0; i < num; i++)
              mn = min(mn, a[r][c][i]);
       ans += mn;

       map<int, int> cnt;
       map<int, pair<int, int>> pos; // number, pos
       for (int i = 0; i < num; i++)
              for (int row : {r - 1, r, r + 1})
                     for (int col : {c - 1, c, c + 1})
                            if (!(row == r && col == c) && row >= 0 && col >= 0 && row < rows && col < cols)
                            {
                                   cnt[a[row][col][i]]++;
                                   pos[a[row][col][i]] = {row, col};
                            }
       for (int i = 1000; i >= -1000; i--)
              if (cnt[i] == 1)
              {
                     recurse(pos[i].first, pos[i].second);
                     break;
              }
}

int sumOfMinAlongPath(string dim, vector<string> arrays)
{
       rows = dim[0] - '0', cols = dim[2] - '0';
       num = arrays.size();
       vector<int> ar[num];

       for (int i = 0; i < num; i++)
       {
              for (int j = 0; j < arrays[i].size(); j++)
              {
                     string s;
                     while (j < arrays[i].size() && arrays[i][j] != ' ')
                            s += arrays[i][j], j++;
                     ar[i].push_back(stoi(s));
              }
       }

       for (int i = 0; i < num; i++)
              for (int j = 0; j < ar[i].size(); j++)
                     a[j / cols][j % cols][i] = ar[i][j];

       recurse(0, 0);

       return ans;
}

signed main()
{
       vector<string> a = {{"9 9 9 8 8 8 7 7 7 6 6 6 5 5 5"}, {"5 6 7 8 5 5 6 7 8 9 5 6 7 8 9"}, {"5 6 3 2 1 9 4 3 2 1 5 4 3 2 1"}, {"5 5 5 6 6 6 7 7 7 8 8 8 9 9 9"}, {"1 2 3 4 5 6 7 8 9 8 7 6 5 4 3"}};

       string s = "5 3";

       cout << sumOfMinAlongPath(s, a) << endl;
}
