// Problem:      P1262 间谍网络
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1262
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-05 16:05:00 

#include <iostream>

#include <vector>
#include <stack>
#include <queue>
#include <set>

#define i64 long long
#define reg register
#define pb push_back
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int inf = 0x3fffffff;

struct Branch { int u, v; };

int n, p, r, ans;
int dfncnt, scccnt;
int dfn[3010], low[3010], scc[3010];
int  in[3010], ind[3010];
int w[3010], nd[3010], dis[3010];
bool instack[3010];

vector<int> g[3010];
vector<Branch> edge;
stack <int> st;
set<int> newg[3010];

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
			nd[scccnt] = min(nd[scccnt], w[now]);
		}
		int now = st.top(); st.pop();
		scc[now] = scccnt;
		instack[now] = false;
		nd[scccnt] = min(nd[scccnt], w[now]);
		// do
		// {
			// int now = st.top(); st.pop();
			// scc[now] = scccnt;
			// instack[now] = false;
			// nd[scccnt] = min(nd[scccnt], w[now]);
		// } while (st.top() != u)
	}
}

inline void buildnew()
{
	for (auto p : edge)
	{
		int x = scc[p.u];
		int y = scc[p.v];
		if (x != y) newg[x].insert(y);
	}
	for (reg int i = 1; i <= scccnt; ++i)
		for (auto x : newg[i])
			++in[x];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> p;
	for (reg int i = 1; i <= n; ++i)
		w[i] = nd[i] = inf;
	for (reg int i = 1, u; i <= p; ++i)
		cin >> u, cin >> w[u];
	cin >> r;
	for (reg int i = 1, u, v; i <= r; ++i)
		cin >> u >> v, g[u].pb(v), edge.pb( {u, v} ), ++ind[v];
	for (reg int i = 1; i <= n; ++i)
		if (ind[i] == 0 && w[i] == inf)
			{ cout << "NO" << endl << i << endl; return 0; }
	for (reg int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	buildnew();
	// for (reg int i = 1; i <= scccnt; ++i)
		// cerr << nd[i] << " \n"[i == scccnt];
	// for (reg int i = 1; i <= n; ++i)
		// cerr << scc[i] << " \n"[i == n];
	// for (reg int i = 1; i <= n; ++i)
		// cerr << w[i] << " \n"[i == n];
	for (reg int i = 1; i <= scccnt; ++i)
		if (in[i] == 0 && nd[i] < inf)
			ans += nd[i];
	cout << "YES" << endl << ans << endl;
	return 0;
}