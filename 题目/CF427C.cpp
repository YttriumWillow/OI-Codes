// Problem:      Checkposts
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF427C
// Memory Limit: 250 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-01 08:06:48 

// Problem:      P3387 【模板】缩点
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3387
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-20 18:58:31 

#include <iostream>

#include <vector>
#include <stack>
#include <queue>
#include <set>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

using namespace std;

const i64 inf = 0xfffffffffff;
const i64 mod = 1e9 + 7;

struct Branch { int u, v; };

i64 n, m, ans, ans2 = 1;
i64 dfncnt, scccnt;
i64   w[100010], wxx[100010];
i64 dfn[100010], low[100010];
i64 scc[100010], cnt[100010];
bool instack[100010];

vector<i64> g[100010];
stack <i64> st;

inline void init()
{
	for (reg int i = 1; i <= 100001; ++i)
		wxx[i] = inf;
}

inline void tarjan(int u)
{
	low[u] = dfn[u] = ++dfncnt; 
	st.push(u); instack[u] = true;
	for (auto v : g[u])
	{
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (instack[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		++scccnt;
		while (st.top() != u)
		{
			int now = st.top(); st.pop();
			scc[now] = scccnt;
			instack[now] = false;
			wxx[scccnt] = min(wxx[scccnt], w[now]);
			// cout << wxx[scccnt] << now;
		}
		int now = st.top(); st.pop();
		scc[now] = scccnt;
		instack[now] = false;
		wxx[scccnt] = min(wxx[scccnt], w[now]);
	}
}

int main()
{
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> w[i];
	init();
	cin >> m;
	for (reg int i = 1, u, v; i <= m; ++i)
		cin >> u >> v, g[u].pb(v);
	for (reg int i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i);
	for (reg int i = 1; i <= scccnt; ++i)
		ans += wxx[i];
	for (reg int i = 1; i <= n; ++i)
		if (wxx[scc[i]] == w[i])
			++cnt[scc[i]];
	for (reg int i = 1; i <= scccnt; ++i)
		ans2 = (ans2 * cnt[i] % mod) % mod;
	cout << ans << ' ' << ans2 % mod << endl;
	return 0;
}