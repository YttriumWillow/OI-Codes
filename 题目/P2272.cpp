// Problem:      P2272 [ZJOI2007]最大半连通子图
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2272
// Memory Limit: 125 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-20 14:41:13 

#include <iostream>

#include <set>
#include <stack>
#include <vector>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, m, p, mod;
int u, v, ans, lgst;
bool vis[N], ins[N];
int dfncnt, scccnt;
int in[N], out[N];
int scc[N], w[N];
int dfn[N], low[N];
int dis[N], cnt[N];
struct Edge { int u, v; Edge(){} Edge(int u, int v): u(u), v(v) {} };
Edge e[M];
stack<int> st;
vector<int> g[N];
set<int> newg[N];

inline void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
	ins[u] = 1; st.push(u);
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
			++w[scccnt];
			scc[u] = scccnt; ins[u] = 0;
			u = st.top(); st.pop();
		} while (dfn[u] != low[u]);
	}
}

inline void build()
{
	for (int i = 1; i <= m; ++i)
		if (scc[e[i].u] != scc[e[i].v])
		{
			++in[scc[e[i].v]], ++out[scc[e[i].u]];
			newg[scc[e[i].u]].insert(scc[e[i].v]);
		}
}

inline void dfs(int u)
{
	vis[u] = 1;
	if (!out[u])
	{
		dis[u] = w[u], cnt[u] = 1;
		lgst = max(lgst, dis[u]);
	}
	for (auto v : newg[u])
	{
		if (!vis[v]) dfs(v);
		if (dis[u] < dis[v] + w[u])
			dis[u] = dis[v] + w[u], cnt[u] = cnt[v] % mod;
		else if (dis[u] == dis[v] + w[u])
			cnt[u] = (cnt[u] + cnt[v]) % mod;
		lgst = max(lgst, dis[u]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> mod;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		g[u].pb(v);
		e[i] = Edge(u, v);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	build();
	for (int i = 1; i <= scccnt; ++i)
		if (!in[i] && !vis[i])
			dfs(i);
	for (int i = 1; i <= scccnt; ++i)
		if (dis[i] == lgst)
			ans = (ans + cnt[i]) % mod;
	cout << lgst << endl << ans << endl;
	return 0;
}