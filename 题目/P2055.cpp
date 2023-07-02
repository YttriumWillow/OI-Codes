// Problem:      P2055 [ZJOI2009] 假期的宿舍
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2055
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-10 20:03:32 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, T, ans, cnt;
int vis[51], match[51];
bool stu[51], home[51];
vector<int> g[51];

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

inline void solve()
{
	for (reg int i = 1; i <= n; ++i) g[i].clear();
	fill(match + 1, match + n + 1, 0);
	ans = cnt = 0;
	
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> stu[i];
	for (reg int i = 1, x; i <= n; ++i)
	{
		cin >> home[i];
		if (!home[i] & stu[i]) g[i].pb(i);
	}
	for (reg int i = 1; i <= n; ++i)
		cnt += (!stu[i] || (!home[i] & stu[i]));
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = 1, x; j <= n; ++j)
			{ cin >> x; if (x && stu[j]) g[i].pb(j); }
	for (reg int i = 1; i <= n; ++i)
		if (!stu[i] || (!home[i] & stu[i]))
		{
			fill(vis + 1, vis + n + 1, 0);
            ans += dfs(i, i);
		}			
	cout << (ans == cnt ? "^_^" : "T_T") << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
		solve();
	return 0;
}