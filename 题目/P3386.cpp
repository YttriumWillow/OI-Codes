// Problem:      P3386 【模板】二分图最大匹配
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3386
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-23 10:02:32 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, e, ans;
int vis[50010];
int match[50010];
vector<int> g[50010];

inline bool dfs(int u, int s)
{
	if (vis[u] == s)
		return 0;
	vis[u] = s;
	for (auto v : g[u])
		if (match[v] == 0 || dfs(match[v], s))
			return match[v] = u, 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> e;
	for (reg int i = 1, u, v; i <= e; ++i)
	{
		cin >> u >> v;
		g[u].pb(v);
	}
	for (reg int i = 1; i <= n; ++i)
		if (dfs(i, i))
			++ans;
	cout << ans << endl;
	return 0;
}