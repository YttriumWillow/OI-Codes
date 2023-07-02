// Problem:      The Largest Clique
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/UVA11324
// Memory Limit: 0 MB
// Time Limit:   3000 ms
// Created Time: 2023-05-20 11:21:22 

#include <iostream>

#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1010;
const int M = 50010;

int T, n, m;

namespace Solution
{
int u, v, ans;
int dfncnt, scccnt;
int dfn[N], low[N];
int scc[N], siz[N];
int  in[N], dis[N];
bool ins[N];
vector<int> g[N];
set<int> newg[N];
stack<int> st;
struct Edge { int u, v; Edge(){} Edge(int u, int v): u(u), v(v) {} };
Edge e[M];

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
		do
		{
			++siz[scccnt];
			scc[u] = scccnt; ins[u] = 0;
			u = st.top(); st.pop();
		} while (dfn[u] != low[u]);
	}
}

inline void build()
{
	for (int i = 1; i <= m; ++i)
		if (scc[e[i].u] != scc[e[i].v])
			newg[scc[e[i].u]].insert(scc[e[i].v]);
	for (int i = 1; i <= scccnt; ++i)
		for (auto x : newg[i])
			++in[x];
}

inline void toposort()
{
	queue<int> q;
	for (int i = 1; i <= scccnt; ++i)
		if (!in[i])
			q.push(i), dis[i] = siz[i];
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto v : newg[u])
		{
			dis[v] = max(dis[v], dis[u] + siz[v]);
			--in[v]; if (in[v] == 0) q.push(v);
		}
	}
}

inline void clear()
{
	for (int i = 1; i <= n; ++i) g[i].clear();
	for (int i = 1; i <= n; ++i) ins[i] = 0;
	for (int i = 1; i <= n; ++i) dfn[i] = low[i] = 0;
	for (int i = 1; i <= m; ++i) e[i] = Edge(0, 0);
	for (int i = 1; i <= scccnt; ++i) in[i] = dis[i] = siz[i] = 0;
	for (int i = 1; i <= scccnt; ++i) newg[i].clear();
	while (!st.empty()) st.pop();
	ans = dfncnt = scccnt = 0;
	// e.clear();
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		g[u].pb(v);
		e[i] = Edge(u, v);
	}
	
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
		
	build();
	toposort();
	
	for (int i = 1; i <= scccnt; ++i)
		ans = max(ans, dis[i]);
	
	cout << ans << endl; clear();
	return 0;
}

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	cin >> T;
    while (T--)
        Solution::main();
    return 0;
}