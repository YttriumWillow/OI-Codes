#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

using namespace std;

int n, q, s;
int u, v, w;
int fa[500010], dep[500010];
int siz[500010], hson[500010];
int top[500010], dfn[500010];
int rnk[500010], tot;
vector<int> g[500010];

inline int build(int u, int d)
{
	hson[u] = 0; siz[hson[u]] = 0;
	dep[u] = d; siz[u] = 1;
	for (auto v : g[u])
	{
		siz[u] += build(v, d + 1); fa[v] = u;
		if (siz[v] > siz[hson[u]]) hson[u] = v;
	}
	return siz[u];
}

inline void cut(int u, int tp)
{
	top[u] = tp; ++tot;
	dfn[u] = tot; rnk[tot] = u;
	if (hson[u])
	{
		cut(hson[u], tp);
		for (auto v : g[u])
			if (v != hson[u]) cut(v, v);
	}
}

inline int LCA(int u, int v)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] > dep[top[v]]) u = fa[top[u]];
		else                           v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

void debug()
{
	cout << "idx" << ": ";
	for (reg int i = 1; i <= n; ++i) cout <<      i << " \n"[i == n];
	cout << "dfn" << ": ";
	for (reg int i = 1; i <= n; ++i) cout << dfn[i] << " \n"[i == n];
	cout << "rnk" << ": ";
	for (reg int i = 1; i <= n; ++i) cout << rnk[i] << " \n"[i == n];
	cout << "top" << ": ";
	for (reg int i = 1; i <= n; ++i) cout << top[i] << " \n"[i == n];
	cout << "siz" << ": ";
	for (reg int i = 1; i <= n; ++i) cout << siz[i] << " \n"[i == n];
		
	for (reg int i = 1; i <= n; ++i)
	{
		cerr << "from " << i << ": ";
		for (auto v : g[i]) cerr << v << ' ';
		cerr << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q >> s;
	for (reg int i = 1; i <= n - 1; ++i)
		cin >> u >> v, g[v].pb(u);
	build(s, 0); cut(s, s);
	// debug();
	while (q--)
	{
		cin >> u >> v;
		cout << LCA(u, v) << endl;
	}
	return 0;
}