// Problem:      P3402 可持久化并查集
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3402
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-05 20:24:32 

#include <iostream>
#include <ext/rope>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~~");

using namespace std;
using namespace __gnu_cxx;

const int N = 2e5 + 10;

int n, m, ver;
int opt, a, b, k;
rope<int> h[N], fa;

inline int find(int x)
{
	if (fa[x] == x) return x;
	int t = find(fa[x]);
	fa.replace(x, t);
	return t;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	
	fa.pb(0);
	for (int i = 1; i <= n; ++i)
		fa.pb(i);
	h[0] = fa;
	
	while (m--)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> a >> b;
			int x = find(a);
			int y = find(b);
			if (x != y) fa.replace(x, y);
			
			h[++ver] = fa;
		}
		if (opt == 2)
		{
			cin >> k;
			fa = h[k];
			
			h[++ver] = fa;
		}
		if (opt == 3)
		{
			cin >> a >> b;
			int x = find(a);
			int y = find(b);
			cout << (x == y) << endl;
			
			h[++ver] = fa;
		}
	}
	return 0;
}