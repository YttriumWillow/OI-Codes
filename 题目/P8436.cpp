// Problem:      P8436 【模板】边双连通分量
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8436
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-06-26 14:55:51 

#include <iostream>

#include <vector>

#define i64 long long
#define endl '\n'
#define qwqw puts("fzy qwq ~");

using namespace std;

const int N = 5e5 + 10;
const int M = 2e6 + 10;

int n, m, u, v;
int dfncnt, dcccnt;
int dfn[N], low[N];
int dcc[N];
bool ins[N];
vector<int> ans[N];

struct Edge
{
	int v, nxt; Edge() {}
	Edge(int v, int x): v(v), nxt(x) {}
};
Edge e[M << 1];
int head[N], tot = 1;
bool b[M << 1];

inline void addedge(int u, int v)
{ e[++tot] = Edge(v, head[u]); head[u] = tot; }

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
	ans[dcccnt].push_back(u);
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (b[i] || dcc[v]) continue;
		dfs(v);
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
		addedge(u, v); addedge(v, u);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i, 0);
	for (int i = 1; i <= n; ++i)
		if (!dcc[i])
			++dcccnt, dfs(i);
	cout << dcccnt << endl;
	for (int i = 1; i <= dcccnt; ++i)
	{
		cout << ans[i].size();
		for (auto x : ans[i])
			cout << ' ' << x;
		cout << endl;
	}
	return 0;
}