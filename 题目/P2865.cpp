// Problem:      P2865 [USACO06NOV]Roadblocks G
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2865
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-21 13:55:32 

#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define pb push_back 
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e3 + 10;
const int M = 1e5 + 10;
const int inf = 0x3fffffff;

int m, n, p;
int u, v, w;
int ans = inf;

struct Edge
{
	int v, w, nxt;
	Edge() {}
	Edge(int v, int w, int x): v(v), w(w), nxt(x) {}
} e[M << 1];
int head[N], tot;

inline void add(int u, int v, int w)
{
	e[++tot] = Edge(v, w, head[u]);
	head[u] = tot;
}

bool vis[N];
int d1[N], d2[N];

inline void SPFA(int s, int d[])
{
	fill(d + 1, d + n + 1, inf);
	fill(vis + 1, vis + n + 1, 0);
	deque<int> q; q.push_back(s);
	d[s] = 0; vis[s] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop_front();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].v, w = e[i].w;
			if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				if (!vis[v])
				{
					vis[v] = 1;
					(!q.empty() && d[v] > d[q.front()]) ? q.push_back(v) : q.push_front(v);
					// q.push_back(v);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}	
	SPFA(1, d1); SPFA(n, d2); p = d1[n];
	for (int i = 1; i <= n; ++i)
		for (int j = head[i]; j; j = e[j].nxt)
			if (d1[i] + d2[e[j].v] + e[j].w > p)
				ans = min(ans, d1[i] + d2[e[j].v] + e[j].w);
	cout << ans << endl;
	return 0;
}