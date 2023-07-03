// Problem:      P2756 飞行员配对方案问题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2756
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-03 13:03:43 

#include <iostream>

#include <queue>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 10010;
const int M = 100010;
const int inf = 0x3fffffff;

struct Arc
{
	int u, v, f, nxt; Arc() { }
	Arc(int u, int v, int f, int nxt): u(u), v(v), f(f), nxt(nxt) { }
} e[M << 1];
int head[N], tot = 1, cnt;

inline void addarc(int u, int v, int f)
{
	e[++tot] = Arc(u, v, f, head[u]), head[u] = tot;
	e[++tot] = Arc(v, u, 0, head[v]), head[v] = tot;
}

int n, m;
int S = 114, T = 514;
int u, v, c;
int d[N]; int cur[N];

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

inline int find(int u, int lmt)
{
	if (u == T) return lmt;
	int flow = 0;
	for (int i = cur[u]; i && flow < lmt; i = e[i].nxt)
	{
		cur[u] = i; int v = e[i].v;
		if (d[v] == d[u] + 1 && e[i].f)
		{
			int t = find(v, min(e[i].f, lmt - flow));
			if (!t) d[v] = -1; 
			e[i].f -= t, e[i ^ 1].f += t, flow += t;
		}
	}
	return flow;
}


inline int dinic()
{
	int res = 0, flow;
	while (bfs())
		while ( flow = find(S, inf) )
			res += flow;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> m >> n;
	while (cin >> u >> v)
	{
		if ((!~u) && (!~v)) break;
		addarc(u, v, 1);
		++cnt;
	}
	for (int i = 1; i <= m; ++i)
		addarc(114, i, 1);
	for (int i = m + 1; i <= n; ++i)
		addarc(i, 514, 1);
	
	cout << dinic() << endl;
	for (int i = 1; i <= cnt; ++i)
		if (!e[i << 1].f )
			cout << e[i << 1].u << ' ' << e[i << 1].v << endl;
	return 0; 
}