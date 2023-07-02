// Problem:      P4782 【模板】2-SAT 问题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4782
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-14 20:39:36 

#include <iostream>

#include <stack>
#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1000010 << 1;

int n, m;
int u, v, a ,b;
int dfscnt, scccnt;
int ins[N], scc[N];
int low[N], dfn[N];
stack<int> st;
vector<int> g[N];

inline void tarjan(int u)
{
	low[u] = dfn[u] = ++dfscnt;
	st.push(u); ins[u] = 1;
	for (auto v: g[u])
	{
		if (!dfn[v])
			tarjan(v),
			low[u] = min(low[u], low[v]);
		else if (ins[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		++scccnt;
		do
		{
			scc[u] = scccnt;
			u = st.top(); st.pop();
			ins[u] = 0;
		} while (low[u] != dfn[u]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= m; ++i)
	{
		cin >> u >> a >> v >> b;
		g[u + n * (a & 1)].pb(v + n * (b ^ 1));
		g[v + n * (b & 1)].pb(u + n * (a ^ 1));
	}
	for (reg int i = 1; i <= n * 2; ++i)
		if (!dfn[i]) tarjan(i);
	for (reg int i = 1; i <= n; ++i)
		if (scc[i] == scc[i + n])
			{ cout << "IMPOSSIBLE" << endl; return 0; }
	cout << "POSSIBLE" << endl;
	for (reg int i = 1; i <= n; ++i)
		cout << (scc[i] < scc[i + n]) << " \n"[i == n];
	return 0;
}