// Problem:      普通平衡树
// Contest:      AcWing
// URL:          https://www.acwing.com/problem/content/255/
// Memory Limit: 64 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-02 21:33:27 

#pragma GCC optimize(2)

#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;
const int inf = 0x7fffffff;

template<typename Tp>
struct BalancedTree
{
    vector<Tp> t; typename::vector<Tp>::iterator pos = t.begin();
    inline void getpos(Tp x) { pos = lower_bound(t.begin(), t.end(), x); }
    inline void insert(Tp x) { getpos(x); t.insert(pos, x); }
    inline void del(Tp x)    { getpos(x); t.erase(pos); }
    inline Tp queryrnk(Tp x) { getpos(x); return pos - t.begin() + 1; }
    inline Tp queryval(Tp x) { return t.at(x - 1); }
    inline Tp prev(Tp x)     { getpos(x); return *(--pos); }
    inline Tp next(Tp x)     { getpos(x); return *upper_bound(t.begin(), t.end(), x); }
};

BalancedTree<int> t;
int n, opt, x;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	while ( n-- )
	{
		cin >> opt >> x;
		if (opt == 1) t.insert(x);
		if (opt == 2) t.del(x);
		if (opt == 3) cout << t.queryrnk(x) << endl;
		if (opt == 4) cout << t.queryval(x) << endl;
		if (opt == 5) cout << t.prev(x) << endl;
		if (opt == 6) cout << t.next(x) << endl;
	}
	return 0;
}