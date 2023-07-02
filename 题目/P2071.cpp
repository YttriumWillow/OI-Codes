// Problem:      P2071 座位安排
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2071
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-10 20:37:29 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, T, ans, cnt;
int vis[4010], match[4010];
vector<int> g[4010];

inline bool dfs(int u, int s)
{
	if (vis[u] == s)
		return 0;
	vis[u] = s;
	for (auto v : g[u])
		if (!match[v] || dfs(match[v], s))
			return match[v] = u, 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (reg int i = 1, s1, s2; i <= n * 2; ++i)
	{
		cin >> s1 >> s2;
		g[i].pb(s1); g[i].pb(s1 + n);
		g[i].pb(s2); g[i].pb(s2 + n);
	}
	for (reg int i = 1; i <= n * 2; ++i)
		ans += dfs(i, i);
	cout << ans << endl;
	return 0;
}