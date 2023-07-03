// Problem:      P3254 圆桌问题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3254
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-03 14:37:47 

#include <iostream>

#include <queue>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~")

using namespace std;

const int N = 1e3 + 10;
const int M = 2e6 + 10;
const int inf = 0x7fffffff;

struct Arc
{
	int u, v, f, nxt; Arc() { }
	Arc(int u, int v, int f, int nxt):
		u(u), v(v), f(f), nxt(nxt) { }
} e[M << 2];
int h[N], tot = 1;
inline void addarc(int u, int v, int f)
{
	e[++tot] = Arc(u, v, f, h[u]), h[u] = tot;
	e[++tot] = Arc(v, u, 0, h[v]), h[v] = tot;
}

int n, m, s, t;
int r, c, cnt, act;
int maxflow;
int d[N], cur[N];

inline bool bfs(int S, int T)
{
	queue<int> q; q.push(S);
	
	memset(d, -1, sizeof d);
	d[S] = 0, cur[S] = h[S];
	
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (!~d[v] && e[i].f)
			{
				d[v] = d[u] + 1;
				cur[v] = h[v];
				if (v == T) return 1;
				q.push(v);
			}
		}
	}
	return 0;
}
inline int find(int u, int lmt, int T)
{
	if (u == T) return lmt;
	int flow = 0; 
	for (int i = cur[u]; i && flow < lmt; i = e[i].nxt)
	{
		cur[u] = i; int v = e[i].v;
		if (d[v] == d[u] + 1 && e[i].f)
		{
			int t = find(v, min(e[i].f, lmt - flow), T);
		   	if (!t) d[v] = -1;
		   	e[i].f -= t, e[i ^ 1].f += t; flow += t;
		}
	}
	return flow;
}
inline int dinic(int S, int T)
{
	int res = 0, flow;
	while (bfs(S, T))
		while ( flow = find(S, inf, T) )
			res += flow;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			addarc(i, j + m, 1);
	act = tot;
	for (int i = 1; i <= m; ++i)
	{
		cin >> r; cnt += r;
		addarc(400, i, r);
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> c;
		addarc(i + m, 401, c);
	}
	maxflow = dinic(400, 401);
	if (maxflow != cnt)
		{ cout << 0 << endl; return 0; }
	else
	{
		cout << 1 << endl;
		for (int i = 2; i <= act; i += 2)
		{
			// cerr << e[i].u << ' ' << e[i].v - m << ' ' << e[i].f << endl;
			if (i > 2 && e[i].u > e[i - 2].u)
				cout << endl;
			if (e[i].f == 0)
				cout << e[i].v - m << ' ';	
		}
	}
	return 0;
}