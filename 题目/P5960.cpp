// Problem:      P5960 【模板】差分约束算法
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5960
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-06 15:13:04 

#include <iostream>

#include <vector>
#include <queue>

#define uint unsigned int
#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

#define PII pair<int, int>

const int inf = 0x3fffffff;

int n, m, s;
vector<PII> g[5010];
int dis[5010];
int cnt[5010];
bool vis[5010];

inline bool SPFA(int s)
{
	queue<int> q;
	for (reg int i = 1; i <= n; ++i)
		dis[i] = inf;
	q.push(s);
	dis[s] = 0; vis[s] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = 0;
		for (reg auto x: g[u])
		{
			int v = x.first, w = x.second;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if (!vis[v])
				{
					vis[v] = 1; ++cnt[v];
					if (cnt[v] >= n + 1) return 0;
					q.push(v);
				}
			}
		}
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= n; ++i)
		g[0].pb({ i, 0 });
	for (reg int i = 1, u, v, w; i <= m; ++i)
	{
		cin >> v >> u >> w;
		g[u].pb({ v, w });
	}
	if (SPFA(0))
		for (reg int i = 1; i <= n; ++i)
			cout << dis[i] << ' ';
	else
		cout << "NO" << endl;
	return 0;
}