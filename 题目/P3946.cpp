// Problem:      P3946 ことりのおやつ（小鸟的点心）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3946
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-04 06:49:52 

#include <iostream>

#include <deque>
#include <queue>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int M = 5e5 + 10;
const int inf = 0x3fffffff;

struct Edge
{
	int v, w, nxt; Edge() { }
	Edge(int v, int w, int n): v(v), w(w), nxt(n) { }
} e[M << 1];
int head[N], tot = 1;
inline void addedge(int u, int v, int w)
{ e[++tot] = Edge(v, w, head[u]), head[u] = tot; }

int n, m;
int s, t, g, q;
int u, v, w;
int h[N], l[N];
int dis[N], tick[N];
bool vis[N];

inline void SPFA(int s)
{
	fill(dis + 1, dis + n + 1, inf);
	fill(vis + 1, vis + n + 1, 0);
	
	deque<int> q; dis[s] = 0;
	q.push_back(s); vis[s] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop_front(); vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (dis[v] > dis[u] + e[i].w && (dis[u] + e[i].w <= tick[v] || v == t))
			{
				dis[v] = dis[u] + e[i].w;
				if (!vis[v])
				{
					vis[v] = 1;
					(!q.empty() && dis[v] < dis[q.front()]) ?
						q.push_front(v) : q.push_back(v);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	
	cin >> n >> m >> s >> t >> g >> q;
	
	for (int i = 1; i <= n; ++i)
		cin >> h[i] >> l[i];
	
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		addedge(u, v, w);
		addedge(v, u, w);
	}
	
	for (int i = 1; i <= n; ++i)
		if (q == 0) tick[i] = inf;
		else tick[i] = (l[i] - h[i]) / q + !!( (l[i] - h[i]) % q );
	
	SPFA(s);
	if (dis[t] == inf || dis[t] > g)
		cout << "wtnap wa kotori no oyatsu desu!" << endl;
	else
		cout << dis[t] << endl;
	return 0;
}