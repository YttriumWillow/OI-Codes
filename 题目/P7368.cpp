// Problem:      P7368 [USACO05NOV]Asteroids G
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P7368
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-12 21:09:07 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, k, ans;
int t, u, v;
int vis[510];
int match[510];
vector<int> g[510];

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

inline void solve(int n)
{
	
	cin >> m >> k; ans = 0;
	
	for (reg int i = 1; i <= n; ++i) g[i].clear();
	fill(match + 1, match + n + 1, 0);
	
	for (reg int i = 1; i <= k; ++i)
	{
		cin >> t >> u >> v;
		if (!u || !v) continue;
		g[u].pb(v + n);
		g[v].pb(u + n);
	}
	for (reg int i = 1; i <= n; ++i)
	{
		fill(vis + 1, vis + n + 1, 0);
        ans += dfs(i);
	}			
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k; ans = 0;
	
	for (reg int i = 1; i <= k; ++i)
	{
		cin >> u >> v;
		g[u].pb(v);
	}
	for (reg int i = 1; i <= n; ++i)
	{
		fill(vis + 1, vis + n + 1, 0);
        ans += dfs(i);
	}			
	cout << ans << endl;
	return 0;
}