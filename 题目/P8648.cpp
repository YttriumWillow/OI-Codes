// Problem:      P8648 [蓝桥杯 2017 省 A] 油漆面积
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8648
// Memory Limit: 256 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-20 19:09:12

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;
int x1, x2, y1, y2;

struct Line
{
    int l, r, y, tag;
    friend bool operator < (Line _x, Line _y) { return _x.y < _y.y; }
} l[10010];

// Range Sum, Range Add
struct SegTree
{
	const int N = 40010;
	
	struct Node { int l, r, sum, tag; int siz() { return r - l + 1; } }
	Node t[N];
	
	#define ls (p << 1)
	#define	rs (p << 1 | 1)
	
	inline void pushup(int p) { t[p].sum = t[ls].sum + t[rs].sum; }
	inline void pushdown(int p)
	{
		if (t[p].tag)
		{
			t[ls].tag += t[p].tag * t[ls].siz();
			t[rs].tag += t[p].tag * t[rs].siz();
			t[ls].tag += t[p].tag;
			t[rs].tag += t[p].tag;
			t[p].tag = 0;
		}
	}
	
	inline void build(int p, int l, int r)
	{
		t[p].l = l, t[p].r = r;
		if (l == r) { t[p].sum = t[p].tag = 0; return; }
		int mid = (l + r) >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
	}
	inline void add(int p, int l, int r, int k)
	{
		if (l <= t[p].l && t[p].r <= r)
		{
			t[p].sum += k * t[p].siz();
			t[p].tag += k;
			return;
		}
		pushdown(p);
		int mid = (l + r) >> 1;
		if (l <= mid)	add(ls, l, r, k);
		if (r >  mid)	add(rs, l, r, k);
		pushup(p);
	}
	inline int query(int p, int l, int r)
	{
		
	}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (reg int i = 1; i <= n; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        l[i * 2 - 1] = Line{x1, x2, y1, 1};
        l[i * 2] = Line{x1, x2, y2, -1};
    }
    sort(l + 1, l + n + n + 1);
    for (reg int i = 1; i <= n; ++i)
    {
    	
    }
    return 0;
}