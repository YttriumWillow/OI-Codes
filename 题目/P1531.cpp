// Problem:      P1531 I Hate It
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1531
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-07 13:53:59 

#include <iostream>

#include <cmath>
#include <climits>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define ls (p << 1)
#define rs (p << 1 | 1)

using namespace std;

char opt;
int n, k, leaf;
int a[1000010];

struct Node
{
	int l, r;
	int max;
} t[4000010];

inline void pushup(const int p) { t[p].max = max( t[ls].max, t[rs].max ); }

// build the segment tree
inline void build(const int p, const int l, const int r)
{	
	t[p].l = l, t[p].r = r;
	if (l == r) { t[p].max = a[l]; return; }
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}

// change one of the point
inline void modify(const int p, const int x, const int y)
{
	if (t[p].l == t[p].r) { if (t[p].max < y) t[p].max = y; return; }
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid)	modify(ls, x, y);
	else			modify(rs, x, y);
	pushup(p);
}

// find the maximum number in [l, r]
inline int query(const int p, const int l, const int r) 
{
	if (l <= t[p].l && t[p].r <= r) { return t[p].max; }
	int mid = (t[p].l + t[p].r) >> 1;
	int ans = -1e9;
	if (l <= mid)	ans = max(ans, query(ls, l, r));
	if (mid  < r)	ans = max(ans, query(rs, l, r));
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i];
		
	build(1, 1, n);
	
 	for (reg int i = 1, x, y; i <= k; ++i)
	{
		cin >> opt >> x >> y;
		switch (opt)
		{
		case 'Q': cout << query(1, x, y) << endl; break;
		case 'U': modify(1, x, y); break;
		default: qwq
		}
	}
	return 0;
}