// Problem:      Almost Union-Find
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/UVA11987
// Memory Limit: 0 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-20 14:02:27

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;

int n, m;

namespace Solution
{
int fa[N], siz[N], sum[N];
inline void init(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		fa[i] = i + n;
		fa[i + n] = i + n;
		siz[i + n] = 1;
		sum[i + n] = i;
	}
}
inline int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
inline void merge(int p, int q)
{
	int x = find(p);
	int y = find(q);
	if (x == y) return;
	fa[x] = y;
	siz[y] += siz[x];
	sum[y] += sum[x];
}
inline void change(int p, int q)
{
	int x = find(p);
	int y = find(q);
	if (x == y) return;
	fa[p] = y;
	--siz[x]; ++siz[y];
	sum[x] -= p; sum[y] += p;
}
inline void query(int p)
{
	int x = find(p);
	cout << siz[x] << ' ' << sum[x] << endl;
}
int main()
{
	int opt, p, q; init(n);
	for (int i = 1; i <= m; ++i)
	{
		cin >> opt >> p;
		if      (opt == 1) cin >> q, merge(p, q);
		else if (opt == 2) cin >> q, change(p, q);
		else if (opt == 3) query(p);
		else qwq
	}
	return 0;
}
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> n >> m)
        Solution::main();
    return 0;
}