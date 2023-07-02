// Problem:      P1407 [国家集训队]稳定婚姻
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1407
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-16 19:39:16 

#include <iostream>

#include <stack>
#include <vector>
#include <unordered_map>

#define i64 long long
#define reg register
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 4010 << 1;

int n, m;
int dfncnt, scccnt;
int dfn[N], low[N];
int scc[N], ins[N];

string F, M, B, G;
stack<int> st;
vector<int> g[N];
unordered_map<string, int> p;

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
			scc[u] = scccnt; ins[u] = 0;
			u = st.top(); st.pop();
		} while (low[u] != dfn[u]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
	{
		cin >> F >> M;
		p[F] = i, p[M] = i + n;
		g[i].pb(i + n);
	}
	cin >> m;
	for (reg int i = 1; i <= m; ++i)
	{
		cin >> G >> B;
		g[p[B]].pb(p[G]);
	}
	for (reg int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	for (reg int i = 1; i <= n; ++i)
		if (scc[i] == scc[i + n])
			cout << "Unsafe" << endl;
		else
			cout << "Safe" << endl;
	return 0;
}