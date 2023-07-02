#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

template <typename Tp>
struct SegTree
{
	#define N 500010
	#define ls (p << 1)
	#define rs (p << 1 | 1)
	const Tp inf = 0xfffffff;
	struct Node { Tp l, r; Tp max, add; } t[N << 2];
	inline void pushup(Tp p) { t[p].max = max(t[ls].max, t[rs].max); }
	inline void pushdown(Tp p)
	{
		if (t[p].add)
		{
			t[ls].max += t[p].add; t[ls].add += t[p].add;
			t[rs].max += t[p].add; t[rs].add += t[p].add;
			t[p].add = 0;
		}
	}
	inline void build(Tp p, Tp l, Tp r)
	{
		t[p].l = l, t[p].r = r;
		if (l == r) { t[p].max = 0; return; }
		Tp mid = (l + r) >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		pushup(p);
	}
	inline void add(Tp p, Tp l, Tp r, Tp k)
	{
		if (l <= t[p].l && t[p].r <= r)
		{ t[p].max += k; t[p].add += k; return; }
		pushdown(p);
		Tp mid = (t[p].l + t[p].r) >> 1;
		if (l <= mid) add(ls, l, r, k);
		if (mid <  r) add(rs, l, r, k);
		pushup(p);
	}
	inline Tp query(Tp p, Tp l, Tp r)
	{
		if (l <= t[p].l && t[p].r <= r) { return t[p].max; }
		pushdown(p);
		Tp mid = (t[p].l + t[p].r) >> 1, res = -inf;
		if (l <= mid) res = max(res, query(ls, l, r));
		if (mid <  r) res = max(res, query(rs, l, r));
		return res;
	}
};

int main()
{
	return 0;
}