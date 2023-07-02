// Problem:      P3810 【模板】三维偏序（陌上花开）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3810
// Memory Limit: 500 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-24 16:55:28 

#include <iostream>

#include <algorithm>

#define i64 long long
#define qwq puts("fzy qwq ~");

using namespace std;

int n, k;

struct Node
{
	int a, b, c;
	int cnt, res;
	friend bool operator != (const Node& _x, const Node& _y)
	{
		if (_x.a != _y.a) return 1;
		if (_x.b != _y.b) return 1;
		if (_x.c != _y.c) return 1;
		return 0;
	}
};

struct BIT
{
	int tree[200010];
	int lowbit(int x) { return x & -x; }
	void add(int pos, int v)
	{
		for (int i = pos; i <= k; i += lowbit(i))
			tree[i] += v;
	}
	int query(int pos)
	{
		int res = 0;
		for (int i = pos; i; i -= lowbit(i))
			res += tree[i];
		return res;
	}
} Tree;

bool cmpX(Node _x, Node _y)
{
	if (_x.a != _y.a) return _x.a < _y.a;
	if (_x.b != _y.b) return _x.b < _y.b;
					  return _x.c < _y.c;
}

bool cmpY(Node _x, Node _y)
{
	if (_x.b != _y.b) return _x.b < _y.b;
					  return _x.c < _y.c;
}

Node e[200010];
Node ue[200010];
int m, t;
int ans[200010];

void CDQ(int l, int r)
{
	if (l == r) return;
	int mid = (l + r) >> 1;
	CDQ(l, mid); CDQ(mid + 1, r);
	sort(ue + l, ue + mid + 1, cmpY);
	sort(ue + mid + 1, ue + r + 1, cmpY);
	int i = l, j = mid + 1;
	while (j <= r)
	{
		while (i <= mid && ue[i].b <= ue[j].b)
			Tree.add(ue[i].c, ue[i].cnt), ++i;
		ue[j].res += Tree.query(ue[j].c); ++j;
	}
	for (int k = l; k < i; ++k)
		Tree.add(ue[k].c, -ue[k].cnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> e[i].a >> e[i].b >> e[i].c;
	sort(e + 1, e + n + 1, cmpX);
	for (int i = 1; i <= n; ++i)
	{
		++t;
		if (e[i] != e[i + 1])
		{
			++m;
			ue[m] = e[i];
			ue[m].cnt = t;
			t = 0;
		}
	}
	CDQ(1, m);
	for (int i = 1; i <= m; ++i)
		ans[ue[i].res + ue[i].cnt - 1] += ue[i].cnt;
	for (int i = 0; i < n; ++i)
		cout << ans[i] << endl;
	return 0;
}