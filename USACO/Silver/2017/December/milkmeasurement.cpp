#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

struct measurement {
  int day;
  int cow;
  int delta;
};

int main() {
  ios_base::sync_with_stdio(false);
  freopen("measurement.in", "r", stdin);
  //freopen("measurement.out", "w", stdout);

  int N;
  int G;
  cin >> N >> G;

  vector<measurement> A(N);
  for (auto& m : A) {
    cin >> m.day >> m.cow >> m.delta;
  }
  sort(A.begin(), A.end(), [](const measurement& a, const measurement& b) {
    return a.day < b.day;
  });

  map<int, int, greater<int> > cnts;
  cnts[0] = N + 1;

  int result = 0;
  map<int, int> mp;
  for (auto& m : A) {
    cout<<m.day<<" "<<m.cow<<" "<<m.delta<<endl;
    int& ref = mp[m.cow];

    bool wastop = ref == cnts.begin()->first;
    int wascnt = cnts[ref]--;
    if (wascnt == 1) {
      cnts.erase(ref);
    }

    ref += m.delta;

    int iscnt = ++cnts[ref];
    bool istop = ref == cnts.begin()->first;
    if (wastop) {
      if (!istop || wascnt != 1 || iscnt != 1) {
        ++result;
        cout<<"changing ----"<<endl;
      }
    } else if (istop) {
      ++result;
      cout<<"changing ---- "<<endl;
    }
  }
  cout << result << endl;

  return 0;
}
