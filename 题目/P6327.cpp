// Problem:      P6327 区间加区间sin和
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6327
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-05 15:23:53 

#include <iostream>

#include <cmath>
#include <iomanip>

#define i64 long long
#define reg register
#define bel(p) ((p - 1) / blk + 1)
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

namespace IO
{
    #define reg register
    template<typename _Tp>
    inline void read(_Tp& x)
    {
        x = 0; char c = getchar(); bool f = 0;
        while (!std::isdigit(c)) f |= c == 45, c = getchar();
        while ( std::isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
        return f ? x = -x : 1, void();
    }
    template<typename _Tp>
    inline void write(_Tp x)
    {
        static char stk[40]; int top = 0;
        if (!x)     return putchar(48), void();
        if (x < 0)  putchar(45), x = -x;
        while (x)   stk[top++] = x % 10, x /= 10;
        while (top) putchar(stk[--top] + 48);
    }
    // read
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
}
using namespace IO;

int n, m, k;
int l, r, opt;
int a[200010];

struct SegTree
{
	#define N 200010
	#define ls (p << 1)
	#define rs (p << 1 | 1) 
	struct Node { int l, r; i64 tag; double sin, cos; };
	Node t[N << 2];
	inline void pushup(int p) { t[p].sin = t[ls].sin + t[rs].sin; t[p].cos = t[ls].cos + t[rs].cos; }
	inline void update(int p, double sin, double cos)
	{
		double rsin = t[p].sin, rcos = t[p].cos;
		t[p].sin = rsin * cos + rcos * sin;
		t[p].cos = rcos * cos - rsin * sin;
	}
	inline void pushdown(int p)
	{
		if (t[p].tag)
		{
			double nsin = sin(t[p].tag), ncos = cos(t[p].tag);
			update(ls, nsin, ncos);
			update(rs, nsin, ncos);
			t[ls].tag += t[p].tag;
			t[rs].tag += t[p].tag;
			t[p].tag = 0;
		}
	}
	inline void build(int p, int l, int r)
	{
		t[p].l = l; t[p].r = r;
		if (l == r) { t[p].sin = sin(a[l]); t[p].cos = cos(a[l]); return; }
		int mid = (l + r) >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		pushup(p);
	}
	inline void modify(int p, int l, int r, int k)
	{
		if (l <= t[p].l && t[p].r <= r)
		{
			update(p, sin(k), cos(k));
			t[p].tag += k;
			return;
		}
		pushdown(p);
		int mid = (t[p].l + t[p].r) >> 1;
		if (l <= mid) modify(ls, l, r, k);
		if (mid <  r) modify(rs, l, r, k);
		pushup(p);
	}
	inline double query(int p, int l, int r)
	{
		if (l <= t[p].l && t[p].r <= r)
			return t[p].sin;
		pushdown(p);
		double res = 0; int mid = (t[p].l + t[p].r) >> 1;
		if (l <= mid) res += query(ls, l, r);
		if (mid <  r) res += query(rs, l, r);
		return res;
	}
};

SegTree t;

int main()
{
	read(n);
	for (reg int i = 1; i <= n; ++i)
		read(a[i]);
	t.build(1, 1, n);
	read(m);
	while (m--)
	{
		read(opt, l, r);
		if (opt == 1)
			read(k), t.modify(1, l, r, k);
		else
			printf("%.1lf\n", t.query(1, l, r));
	}
	return 0;
}