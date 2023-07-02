// Problem:      P5782 [POI2001] 和平委员会
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5782
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-14 21:09:58 

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
			scc[u] = scccnt; ins[u] = 0;
			u = st.top(); st.pop();
		} while (low[u] != dfn[u]);
	}
}

#define build(x) (x + (x % 2 ? 1 : -1)) 
// #define build(x) ((x % 2) ? x + 1 : x - 1)

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		g[u].pb(build(v));
		g[v].pb(build(u));
	}
	for (reg int i = 1; i <= n * 2; ++i)
		if (!dfn[i]) tarjan(i);
	for (reg int i = 1; i <= n * 2; i += 2)
		if (i % 2 && scc[i] == scc[i + 1])
			{ cout << "NIE" << endl; return 0; }
	for (reg int i = 1; i <= n * 2; ++i)
		if (scc[i] < scc[build(i)])
			cout << i << endl;
	return 0;
}