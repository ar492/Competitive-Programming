#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <utility>
#include <iterator>

#include <queue>
#include <deque>
#include <stack>

#include <stdlib.h>
#include <functional>
#include <fstream>
#include <cassert>
#include <numeric>

#include <stdio.h>
#include <time.h>
#include <random>

#define what(x) cout <<"              LINE "<<__LINE__<<"|>> "<<#x << " = " << (x)<<endl
#define what2(x, y) cout <<"              LINE "<<__LINE__<<"|>> ("<<#x <<", "<<#y<< ") = (" << (x)<<", "<<(y)<<")"<<endl
#define what3(x, y, z) cout <<"              LINE "<<__LINE__<<"|>> ("<<#x <<", "<<#y<< ", "<<#z<<") = (" << (x)<<", "<<(y)<<", "<<(z)<<")"<<endl
using namespace std;
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }

/*


#ifdef LOCAL
       #include "C:\\Users\\gbpol\\Desktop\\Useful\\cp.h"
#else
       #include <bits/stdc++.h>
#endif



*/
