// Problem:      P1110 [ZJOI2007] 报表统计
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1110
// Memory Limit: 158 MB
// Time Limit:   2000 ms
// Created Time: 2023-06-26 13:46:02 

#include <iostream>

#include <cmath>
#include <cstring>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e6 + 10;
const int inf = 0x3fffffff;
const int rng = 0x7fffffff;

#include <vector>
#include <algorithm>

// wait what is this really a balanced tree
template<typename Tp>
struct BalancedTree
{
    vector<Tp> t; typename::vector<Tp>::iterator pos = t.begin();
    inline void getpos(Tp x) { pos = lower_bound(t.begin(), t.end(), x); }
    inline void insert(Tp x) { getpos(x); t.insert(pos, x); }
    inline void del(Tp x)    { getpos(x); t.erase(pos); }
    inline Tp queryrnk(Tp x) { getpos(x); return pos - t.begin() + 1; }
    inline Tp queryval(Tp x) {  return t.at(x - 1); }
    inline Tp prev(Tp x)     { getpos(x); return *(--pos); }
    inline Tp next(Tp x)     { getpos(x); return *upper_bound(t.begin(), t.end(), x); }
};

int n, m, x, k;
int dt = inf;
int dst = inf;
vector<int> a[N];
BalancedTree<int> t;
string opt;

inline void insert(int x, int k)
{
	a[x].pb(k);
	dt = min({ dt, abs(k - a[x].back()), abs(k - a[x + 1][0]) });
	t.insert(k);
	dst = min({ dst, abs(k - t.prev(k)), 
					 abs(k - t.next(k)) });
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	t.insert(-inf); t.insert(inf);
	a[0].pb(-inf); a[n + 1].pb(-inf);
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> x, a[i].pb(x); t.insert(x);
		dt = min(dt, abs( x - a[i - 1][0] ));
		dst = min({ dst, abs(x - t.prev(x)), 
						 abs(x - t.next(x)) });
	}
	cerr << dt << ' ' << dst << endl;
	for (int i = 1; i <= m; ++i)	
	{
		cin >> opt;
		switch (opt[4])
		{
			case 'R': cin >> x >> k; insert(x, k); break;
			case 'G': cout << dt << endl; break;
			case 'S': cout << dst << endl; break;
			default: qwq
		}
	}
	return 0;
}