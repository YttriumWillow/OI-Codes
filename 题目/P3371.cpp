// Problem:      P3371 【模板】单源最短路径（弱化版）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3371
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-06 13:48:58 

#include <iostream>

#include <vector>
#include <queue>

#define uint unsigned int
#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

#define PII pair<int, uint>

const int inf = 0x7fffffff;

int n, m, s;
vector<PII> g[10010];
uint dis[10010];
int vis[10010];

inline void SPFA(int s)
{
	queue<int> q;
	for (reg int i = 1; i <= n; ++i)
		dis[i] = inf;
	q.push(s);
	dis[s] = 0; vis[s] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (reg auto x: g[u])
		{
			int v = x.first, w = x.second;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if (vis[v] <= n)
					++vis[v], q.push(v);
				else
					{ cout << inf << endl; exit(0); }
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> s;
	for (reg int i = 1, u, v, w; i <= m; ++i)
	{
		cin >> u >> v >> w;
		g[u].pb({ v, w });
	}
	SPFA(s);
	for (reg int i = 1; i <= n; ++i)
		cout << dis[i] << ' ';
	return 0;
}