#ifndef COMMON_HPP
#define COMMON_HPP


#include <bits/stdc++.h>
using namespace std;

#define FOR(cont,start,end)	for(int (cont) = (start), cont##_END = (end);   (cont) <  cont##_END; (cont)++)
#define ROF(cont,start,end)	for(int (cont) = (end)-1, cont##_END = (start); (cont) >= cont##_END; (cont)--)
#define LOG(x)				(31 - __builtin_clz(x))
#define W(x)				cerr << "\033[31m" << #x << " = " << x << "\033[0m" << endl;

#define oo 					int(1e9)
#define ep					int(1e-9)
#define pb					emplace_back
#define ff					first
#define ss					second
#define sz(v)				ll(v.size())

using ll = long long;
using llu = unsigned ll;
using uint = unsigned;
using ii = pair<int,int>;




#define DATA_PATH "data"



#endif//COMMON_HPP
