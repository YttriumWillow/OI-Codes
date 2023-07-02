// Problem:      P2812 校园网络【[USACO]Network of Schools加强版】
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2812
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-20 11:12:07 

// Problem:      P2746 [USACO5.3]校园网Network of Schools
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2746
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-16 21:10:18 

#include <iostream>

#include <stack>
#include <vector>

#define i64 long long
#define reg register
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 10010;

int n, m, v, ans1, ans2;
int dfncnt, scccnt;
int dfn[N], low[N];
int in[N], out[N];
int scc[N]; bool ins[N];
stack<int> st;
vector<int> g[N];
#define Pii pair<int, int>
vector<Pii> e;

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
		} while (dfn[u] != low[u]);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
	{
		while (cin >> v && v)
			g[i].pb(v),
			e.pb({ i, v });
	}
	for (reg int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	for (auto x : e)
		if (scc[x.first] != scc[x.second])
		{
			++out[scc[x.first]];
			++in[scc[x.second]];
		}
	for (reg int i = 1; i <= scccnt; ++i)
	{
		ans1 += (in[i] == 0);
		ans2 += (out[i] == 0);
	}
	if (scccnt == 1) cout << 1 << endl << 0 << endl;
	else cout << ans1 << endl << max(ans1, ans2) << endl;
	return 0;
	
}