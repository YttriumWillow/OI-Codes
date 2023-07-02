// Problem:      P2860 [USACO06JAN] Redundant Paths G
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2860
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-28 21:01:50 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e4 + 10;
const int M = 1e5 + 10;

int n, m, u, v, ans;
int dfncnt, dcccnt;
int dfn[N], low[N];
int dcc[N], deg[N];
bool b[M << 1];

struct Edge { int u, v, nxt; };
Edge e[M << 1];
int head[N], tot = 1;

inline void addedge(int u, int v)
{ e[++tot] = { u, v, head[u] }, head[u] = tot; }

inline void tarjan(int u, int ine)
{
	dfn[u] = low[u] = ++dfncnt;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dfn[v])
		{
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			
			if (dfn[u] < low[v])
				b[i] = b[i ^ 1] = 1;
		}
		else if (i != (ine ^ 1))
			low[u] = min(low[u], dfn[v]);
	}
}

inline void dfs(int u)
{
	dcc[u] = dcccnt;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!b[i] && !dcc[v]) dfs(v);
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
		addedge(u, v);
		addedge(v, u);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i, 0);
	for (int i = 1; i <= n; ++i)
		if (!dcc[i])
			++dcccnt, dfs(i);
	for (int i = 1; i <= m; ++i)
		if (dcc[e[i << 1].u] != dcc[e[i << 1].v])
		{
			++deg[dcc[e[i << 1].u]];
			++deg[dcc[e[i << 1].v]];
		}
	for (int i = 1; i <= dcccnt; ++i)
		ans += (deg[i] == 1);
	cout << ((ans + 1) >> 1) << endl;
	return 0;
}