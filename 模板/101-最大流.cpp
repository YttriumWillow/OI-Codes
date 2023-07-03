// Problem:      #101. 最大流
// Contest:      LibreOJ
// URL:          https://loj.ac/p/101
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-07-02 19:20:09 

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 10010;
const int M = 100010;
const int inf = 0x37ffffff;

struct Arc
{
	int v; i64 f; int nxt; Arc() { }
	Arc(int v, i64 f, int nxt): v(v), f(f), nxt(nxt) { }
} e[M << 1];
int head[N], tot = 1;

inline void addarc(int u, int v, i64 f)
{
	e[++tot] = Arc(v, f, head[u]), head[u] = tot;
	e[++tot] = Arc(u, 0, head[v]), head[v] = tot;
}

int n, m, S, T;
int u, v, c;
i64 d[N]; int cur[N];

inline bool bfs()
{
	queue<int> q; q.push(S);
	memset(d, -1, sizeof d);
	d[S] = 0, cur[S] = head[S];
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (!~d[v] && e[i].f)
			{
				d[v] = d[u] + 1;
				cur[v] = head[v];
				if (v == T) return 1;
				q.push(v);
			}
		} 
	}
	return 0;
}

inline i64 find(int u, int lmt)
{
	if (u == T) return lmt;
	i64 flow = 0;
	for (int i = cur[u]; i && flow < lmt; i = e[i].nxt)
	{
		cur[u] = i; int v = e[i].v;
		if (d[v] == d[u] + 1 && e[i].f)
		{
			i64 t = find(v, min(e[i].f, lmt - flow));
			if (!t) d[v] = -1; 
			e[i].f -= t, e[i ^ 1].f += t, flow += t;
		}
	}
	return flow;
}


inline i64 dinic()
{
	i64 res = 0, flow;
	while (bfs())
		while ( flow = find(S, inf) )
			res += flow;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> S >> T;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> c;
		addarc(u, v, c);
	}
	cout << dinic() << endl;
	return 0;
}