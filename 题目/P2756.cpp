// Problem:      P2756 飞行员配对方案问题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2756
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-28 19:51:38 

#include <iostream>

#include <vector>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m;
int u, v, ans;
int match[210];
bool vis[210];
vector<int> g[210];

inline bool dfs(int u)
{
	for (auto v : g[u])
		if (!vis[v])
		{
			vis[v] = 1;
			if (!match[v] || dfs(match[v]))
				return match[v] = u, 1;
		}
	return 0;
}

int main()
{
	cin >> m >> n;
	while (cin >> u >> v && !(u == -1 && v == -1))
		g[u].pb(v);
	for (int i = 1; i <= n; ++i)
	{
		fill(vis + 1, vis + (n + m) + 1, 0);
		ans += dfs(i);
	}
	cout << ans << endl;
	for (int i = m + 1; i <= n; ++i)
		if (match[i])
			cout << match[i] << ' ' << i << endl;
	return 0;
}