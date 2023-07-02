// Problem:      P3157 [CQOI2011]动态逆序对
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3157
// Memory Limit: 500 MB
// Time Limit:   1500 ms
// Created Time: 2023-03-29 19:49:37 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define lowbit(x) (x & -x)

using namespace std;

struct Node { int val, del, ans; } a[100010];

int n, m;
int  rmv[100010];
int tree[100010];
i64 ans;

inline bool cmpX(const Node& _x, const Node& _y) { return _x.val < _y.val; }
inline bool cmpY(const Node& _x, const Node& _y) { return _x.del < _y.del; }

inline void add(const int& x, const int& v) { for (reg int i = x; i <= n + 1; i += lowbit(i)) tree[i] += v; }
inline int query(const int& x) { int res = 0; for (reg int i = x; i; i -= lowbit(i)) res += tree[i]; return res; }

void CDQ(const int& l, const int& r)
{
	if (l == r) { return; }
	int mid = (l + r) >> 1, i, j;
	CDQ(l, mid); CDQ(mid + 1, r);	
	
	i = l + 1; j = mid + 1;
	while (i <= mid)
	{
		while (a[i].val > a[j].val && j <= r) { add(a[j].del, 1); ++j; }
		a[i].ans += query(m + 1) - query(a[i].del); ++i;
	}
	i = l + 1; j = mid + 1;
	while (i <= mid)
	{
		while (a[i].val	> a[j].val && j <= r) { add(a[j].del, -1); ++j; }
		++i;
	}
	i = mid; j = r;
	while (j > mid)
	{
		while (a[i].val > a[j].val && i > l) { add(a[i].del, 1); --i; }
		--j;
	}
	i = mid; j = r;
	while (j > mid)
	{
		while (a[i].val > a[j].val && i > l) { add(a[i].del, -1); --i; }
		--j;
	}
	sort(a + l, a + r + 1, cmp1)
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i].val, 
	return 0;
}