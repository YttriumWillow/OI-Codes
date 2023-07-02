// Problem:      P3385 【模板】负环
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3385
// Memory Limit: 256 MB
// Time Limit:   2000 ms
// Created Time: 2023-07-02 07:07:09 

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <iostream>

#include <queue>
#include <deque>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 3010;
const int M = 5010;
const i64 inf = 0x3fffffffffffff;

struct Edge
{
	int v; i64 w; int nxt; Edge() { }
	Edge(int v, i64 w, int n): v(v), w(w), nxt(n) { }
} e[M << 1];
int head[N], tot;
inline void addedge(int u, int v, i64 w)
{ e[++tot] = Edge(v, w, head[u]), head[u] = tot; }

int n, m, u, v, w;
int cnt[N], pre[N], pt, x;
i64 dis[N];
bool vis[N], faq[N];

inline int SPFA(int s)
{
	fill(dis + 1, dis + n + 1, inf);
	for (int i = 1; i <= n; ++i) pre[i] = i;
	
	deque<int> q; q.push_back(s);
	vis[s] = 1; dis[s] = 0;
	
	while (!q.empty())
	{
		int u = q.front(); q.pop_front(); vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].v; i64 w = e[i].w;
			
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				pre[v] = u;
				
				if (!vis[v])
				{
					vis[v] = 1;
					if (++cnt[v] >= n) return v;
					
					q.push_back(v);
					
					if (dis[q.front()] > dis[q.back()])
					{
						x = q.front(); q.pop_front();
						q.push_front(q.back());
						q.pop_back(); q.push_back(x);
					}
					
				}
			}
		}
	}
	return 0;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		addedge(0, i, 0);
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		addedge(u, v, w);
		if (u == v && w < 0)
			{ cout << "YES " << u << ' ' << u << endl; return 0; } 
	}
	pt = SPFA(0);
	
	if (pt == 0)
		cout << "NO" << endl;
	else
	{
		cout << "YES " << pt;
		x = pre[pt]; faq[pt] = 1;
		while (x != pt && !faq[x])
		{
			faq[x] = 1;
			cout << ' ' << x;
			x = pre[x];
		}
		cout << ' ' << pt << endl;
	}
	return 0;
}