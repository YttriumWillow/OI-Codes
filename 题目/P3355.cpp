// Problem:      P3355 骑士共存问题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3355
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-05 09:06:13 

#include <iostream>

#include <queue>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 8e4 + 10;
const int M = 2e6 + 10;
const int inf = 0x3fffffff;

struct Arc
{
	int v, f, nxt; Arc() { }
	Arc(int v, int f, int nxt):
		v(v), f(f), nxt(nxt) { }
} e[M << 1];
int h[N], tot = 1;
inline void addarc(int u, int v, int f)
{
	e[++tot] = Arc(v, f, h[u]), h[u] = tot;
	e[++tot] = Arc(u, 0, h[v]), h[v] = tot;
}

int n, m, x, y;
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
				d[v] = d[u] + 1; cur[v] = h[v];
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

#define idx(x, y) (n * (x - 1) + y)
#define chk(x, y) ( x < 1 || y < 1 || x > n || y > n || flg[idx(x, y)] )

bool flg[N]; int S, T;
int dx[8] = { -2, -2, -1, 1, 2,  2,  1, -1 };
int dy[8] = { -1,  1,  2, 2, 1, -1, -2, -2 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 1; i <= m; ++i)
	{
		cin >> x >> y;
		flg[idx(x, y)] = 1;
	}
	
	S = 0, T = n * n + 1;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (flg[idx(i, j)]) continue;
			
			if ((i + j) & 1)
			{
				addarc(S, idx(i, j), 1);
				
				for (int k = 0; k < 8; ++k)
				{
					x = i + dx[k], y = j + dy[k];
					if ( chk(x, y) ) continue;
					addarc(idx(i, j), idx(x, y), 1);
				}
			}
			else
				addarc(idx(i, j), T, 1);
		}
		
	
	cout << n * n - m - dinic(S, T) << endl;
	return 0;
}