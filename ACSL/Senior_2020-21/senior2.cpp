

#include <bits/stdc++.h>
#define int long long
using namespace std;

string rearrangedString(string s)
{
       vector<char> freq[101];
       map<char, int> f;
       for (char c : s)
              if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                     f[c]++;
       for (pair<char, int> i : f)
              freq[i.second].push_back(i.first);
       string ans;
       bool ascend = true;
       for (int i = 100; i >= 1; i--)
       {
              if (freq[i].size())
              {
                     sort(freq[i].begin(), freq[i].end());
                     ans += to_string(i);
                     string ans2;
                     for (char j : freq[i])
                            ans2 += j;
                     sort(ans2.begin(), ans2.end());
                     if (!ascend)
                            reverse(ans2.begin(), ans2.end());
                     ans += ans2 + ',';
                     ascend ^= 1;
              }
       }
       if (ans.size())
              ans.pop_back();
       return ans;
}

signed main()
{
       string s = "--";
       cout << rearrangedString(s);
}
