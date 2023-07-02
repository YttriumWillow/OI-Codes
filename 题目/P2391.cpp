// Problem:      P2391 白雪皑皑
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2391
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-07 20:29:01 

#include <iostream>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, p, q;
int a[1000010];
int fa[1000010];

inline int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> p >> q;
	for (reg int i = 1; i <= n + 1; ++i)
		fa[i] = i;
	for (reg int i = m; i >= 1; --i)
	{
		int l = (i * p + q) % n + 1;
		int r = (i * q + p) % n + 1;
		// cerr << l << ' ' << r << endl;
		if (l > r) swap(l, r);
		
		int p = find(l);
		while (p <= r)
		{
			a[p] = i;
			int nxt = find(p);
			fa[p] = p + 1;
			p = nxt;
		}
	}
	for (reg int i = 1; i <= n; ++i)
		cout << a[i] << endl;
	return 0;
}