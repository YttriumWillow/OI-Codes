// Problem:      P3627 [APIO2009] 抢掠计划
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3627
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-25 21:25:44 

#include <iostream>

#include <stack>
#include <queue>
#include <vector>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 500010;
const int M = N;

int n, m, s, p;
int u, v, x, ans;
int a[N], w[N];
int dfscnt, scccnt;
int dfn[N], low[N];
int scc[N], dis[N];
bool ins[N], vis[N];
vector<int> g[N];
vector<int> newg[N];
stack<int> st;
struct Edge { int u, v; Edge(){} Edge(int u, int v): u(u), v(v) {} };
Edge e[M];

inline void tarjan(int u)
{
	dfn[u] = low[u] = ++dfscnt;
	st.push(u); ins[u] = 1;
	for (auto v : g[u])
	{
		if (!dfn[v])
			tarjan(v),
			low[u] = min(low[u], low[v]);
		else if (ins[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		++scccnt;
		do {
			w[scccnt] += a[u];
			scc[u] = scccnt; ins[u] = 0;
			u = st.top(); st.pop();
		} while (dfn[u] != low[u]);
	}
}

inline void build()
{
	for (int i = 1; i <= m; ++i)
		if (scc[e[i].u] != scc[e[i].v])
			newg[scc[e[i].u]].pb(scc[e[i].v]);
}

inline void SPFA(int s)
{
	queue<int> q;
	q.push(s); vis[s] = 1;
	dis[s] = w[s];
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (auto v : newg[u])
		{
			if (dis[v] < dis[u] + w[v])
			{
				dis[v] = dis[u] + w[v];
				if (!vis[v])
					q.push(v), vis[v] = 1;
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
		cin >> u >> v;
		g[u].pb(v);
		e[i] = Edge(u, v);
	}
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	cin >> s >> p;
	build(); SPFA(scc[s]);
	for (int i = 1; i <= p; ++i)
		cin >> x, ans = max(ans, dis[scc[x]]);
	cout << ans << endl;
	
	
	// for (int i = 1; i <= n; ++i)
		// cerr << scc[i] << " \n"[i == n];
	// for (int i = 1; i <= scccnt; ++i)
	// {
		// cerr << i << ": ";
		// for (auto x : newg[i])
			// cerr << x << ' ';
		// cerr << endl;
	// }
	// for (int i = 1; i <= scccnt; ++i)
		// cerr << dis[i] << " \n"[i == scccnt];
	return 0;
}