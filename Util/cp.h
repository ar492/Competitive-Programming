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
#include <chrono>

#define what(x) cout <<"              LINE "<<__LINE__<<"|>> "<<#x << " = " << (x)<<endl
#define what2(x, y) cout <<"              LINE "<<__LINE__<<"|>> ("<<#x <<", "<<#y<< ") = (" << (x)<<", "<<(y)<<")"<<endl
#define what3(x, y, z) cout <<"              LINE "<<__LINE__<<"|>> ("<<#x <<", "<<#y<< ", "<<#z<<") = (" << (x)<<", "<<(y)<<", "<<(z)<<")"<<endl
using namespace std;


bool file_cmp(string file1, string file2){
	ifstream in1(file1); ifstream in2(file2);
	vector<char> input1, input2;
	char c;
	while (in1 >> c) input1.emplace_back(c);
	while (in2 >> c) input2.emplace_back(c);
	return(input1 == input2);
}
/*


#ifdef LOCAL
	#include "C:\\Users\\gbpol\\Desktop\\Useful\\cp.h"
#else
	#include <bits/stdc++.h>
#endif



*/
