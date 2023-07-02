// Problem:      P3385 【模板】负环
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3385
// Memory Limit: 256 MB
// Time Limit:   2000 ms
// Created Time: 2023-07-02 07:07:09 

#include <iostream>

#include <deque>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e3 + 10;
const int M = 3e3 + 10;
const int inf = 0x77ffffff;

struct Edge
{
	int v, w, nxt; Edge() { }
	Edge(int v, int w, int n): v(v), w(w), nxt(n) { }
} e[M << 1];
int head[N], tot;
inline void addedge(int u, int v, int w)
{ e[++tot] = Edge(v, w, head[u]), head[u] = tot; }

int n, m, u, v, w;
int dis[N], cnt[N];
int pre[N], pt, x;
bool vis[N];

inline int SPFA(int s)
{
	fill(vis + 1, vis + n + 1, 0);
	fill(dis + 1, dis + n + 1, inf);
	fill(cnt + 1, cnt + n + 1, 0);
	
	queue<int> q({ s }); vis[s] = 1; dis[1] = 0;
	while (!q.empty())
	{
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].v, w = e[i].w;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				pre[v] = u;
				if (!vis[v])
				{
					if (++cnt[v] >= n) return v;
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		addedge(u, v, w);
	}
	if ( pt = SPFA(1) )
	{
		cout << "YES "; x = pt;
		while (pre[x] != pt)
		{
			cout << x;
			x = pre[x];
		}
	}
	else
		cout << "NO" << endl;
	return 0;
}