// Problem:      P1525 [NOIP2010 提高组] 关押罪犯
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1525
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-16 20:13:52 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, ans;
int color[20010];

vector< pair<int, int> > g[20010];

inline bool dfs(int u, int col, int mid)
{
	color[u] = col;
	for (auto it : g[u])
	{
		int v = it.first, w = it.second;
		
		if (w <= mid) continue;
		if (color[v])
		{
			if (color[v] == col)
				return false;
		}
		else if (!dfs(v, 3 - col, mid))
			return false;
	}
	return true;
}

inline bool check(int mid)
{
	for (reg int i = 1; i <= n; ++i)
		color[i] = 0;
	for (reg int i = 1; i <= n; ++i)
		if (color[i] == 0)
			if (!dfs(i, 1, mid))
				return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1, u, v, w; i <= m; ++i)
	{
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	int l = 0, r = 1e9;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid - 1,
			ans = mid;
		else
			l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}