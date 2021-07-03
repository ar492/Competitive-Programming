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
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if (vec.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < vec.size() - 1; i++) {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& deq) {
    if (deq.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < deq.size() - 1; i++) {
        out << deq[i] << ", ";
    }
    return out << deq.back() << ']';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::multiset<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_multiset<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";   
        }
    }
    return out << '}';
}

// this part is copied from SO
template<typename Type, unsigned N, unsigned Last>
struct TuplePrinter {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value) << ", ";
        TuplePrinter<Type, N + 1, Last>::print(out, value);
    }
};

template<typename Type, unsigned N>
struct TuplePrinter<Type, N, N> {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value);
    }
};

template<typename... Types>
std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& value) {
    out << '(';
    TuplePrinter<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out, value);
    return out << ')';
}

bool file_cmp(string file1, string file2){
       ifstream in1(file1); ifstream in2(file2);
       vector<char> input1, input2;
       char c;
       while(in1>>c) input1.emplace_back(c);
       while(in2>>c) input2.emplace_back(c);
       return(input1==input2);
}
/*


#ifdef LOCAL
       #include "C:\\Users\\gbpol\\Desktop\\Useful\\cp.h"
#else
       #include <bits/stdc++.h>
#endif



*/
