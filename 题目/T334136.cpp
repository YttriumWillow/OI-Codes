// Problem:      T334136 绫华の狗
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T334136
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-07 20:56:02 

#include <iostream>

#include <algorithm>

#define i64 long long 
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int fa[100000010];
inline int find(int x)
{ return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y)
{ fa[x] = y; }

struct Seg
{
	int l, r, k;
	Seg() {}
	Seg(int l, int r, int k): l(l), r(r), k(k) {} 
	friend bool operator < (Seg _x, Seg _y)
	{ return _x.k > _y.k; }
};

int n, m, p;
int t1, t2;
i64 w1, w2;
Seg seg[100010];
int a[100000010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> p;
	for (reg int i = 1, t, w; i <= n; ++i)
		cin >> t >> w, t1 += t, w1 += w;
	for (reg int i = 1, l, r, k; i <= m; ++i)
	{
		cin >> l >> r >> k; --r; r = min(r, p);
		seg[i] = Seg(l, r, k);
	}
	sort(seg + 1, seg + m + 1);
	
	for (reg int i = 1; i <= p + 1; ++i)
		fa[i] = i;
	for (reg int i = 1; i <= m; ++i)
	{
		if (seg[i].l > seg[i].r) continue;
		int pp = find(seg[i].l);
		while (pp <= seg[i].r)
		{
			a[pp] = seg[i].k;
			int nxt = find(pp + 1);
			fa[pp] = pp + 1;
			pp = nxt;
		}
	}
	nth_element(a + 1, a + t1 + 1, a + p + 1);
	for (reg int i = t1 + 1; i <= p; ++i)
		w2 += a[i];
	cout << w1 << ' ' << w2 << endl;
	return 0;
}