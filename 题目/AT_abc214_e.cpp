// Problem:      [ABC214E] Packing Under Range Regulations
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/AT_abc214_e
// Memory Limit: 1 MB
// Time Limit:   3000 ms
// Created Time: 2023-05-13 13:31:05 

#include <iostream>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

struct Seg
{
	int l, r;
	friend bool operator < (Seg _x, Seg _y)
	{ return (_x.l != _y.l) ? (_x.l < _y.l) : (_x.r < _y.r); }
}

inline void solve()
{
	cin >> n; q.clear();
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i].l >> a[i].r;
	sort(a + 1, a + n + 1);
	while (!empty())
	{
		
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
		solve();
	return 0;
}