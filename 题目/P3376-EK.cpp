// Problem:      P3376 【模板】网络最大流
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3376
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-09 21:10:05 

#include <iostream>

#include <algorithm>
#include <queue>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 210;
const int M = 5e3 + 10;
const int inf = 0x3fffffff;

struct Edge
{
	int v, nxt; i64 w;
	Edge() { }
	Edge(int v, i64 w, int nxt): v(v), nxt(nxt), w(w) { }
};

int n, m, s, t;
int u, v, w, tot = 1, head[N]; // tot 初始化为 1
int pre[N], fe[N][N];
i64 flow[N];
Edge e[M << 1];

inline void addedge(int u, int v, int w)
{
	e[++tot] = Edge(v, w, head[u]);
	head[u] = tot;
}

inline bool bfs()
{
	fill(pre + 1, pre + n + 1, 0);
	queue<int> q; q.push(s); flow[s] = inf;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		if (u == t) break;
		for (reg int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].v; i64 w = e[i].w;
			if (w > 0 && !pre[v])
			{
				flow[v] = min(flow[u], w);
				pre[v] = i; q.push(v);
				if (u == t) return 1;
			}
		}
	}
	return pre[t];
}

inline i64 EK()
{
	i64 res = 0;
	while (bfs())
	{
		res += flow[t];
		for (reg int i = t; i != s; i = e[pre[i] ^ 1].v)
		{
			e[pre[i]].w -= flow[t];
			e[pre[i] ^ 1].w += flow[t];
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> s >> t;
	for (reg int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		if (!fe[u][v])
		{
			addedge(u, v, w);
			fe[u][v] = tot;
			addedge(v, u, 0);
		}
		else e[fe[u][v]].w += w;
	}
	cout << EK() << endl;
	return 0;
}