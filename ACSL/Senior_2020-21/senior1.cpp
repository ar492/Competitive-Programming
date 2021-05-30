#include <bits/stdc++.h>
using namespace std;

long long toDec(string s)
{
       long long c = 1, ans = 0;
       for (int i = s.length() - 1; i >= 0; i--)
       {
              ans += (s[i] >= 'A' ? (s[i] - 'A' + 10) : (s[i] - '0')) * c;
              c *= 16;
       }
       return ans;
}

string toHex(long long d)
{
       vector<char> hex;
       while (d > 0)
       {
              int r = d % 16;
              hex.push_back((r >= 10) ? (char)(r - 10 + 'A') : (char)(r + '0'));
              d /= 16;
       }
       string s;
       for (char c : hex)
              s += c;
       reverse(s.begin(), s.end());
       return s;
}

char sumOfLastRow(string s, string d, int r) //d is in hex
{
       long long start = toDec(s), increment = toDec(d);
       start += (((long long)r * (r - 1) / 2)) * (increment);
       string lastRow;
       for (int i = 0; i < r; i++)
       {
              lastRow += toHex(start);
              start += increment;
       }
       while (lastRow.length() > 1)
       {
              long long sum = 0;
              for (char c : lastRow)
                     sum += (toDec(string() + c));
              lastRow = toHex(sum);
       }
       return (lastRow[0]);
}

int main()
{
       cout << sumOfLastRow("A", "9", 5);
       cout << sumOfLastRow("ABC", "F", 4);
       cout << toDec("FF") << endl;
       return 0;
}