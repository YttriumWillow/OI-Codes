// Problem:      P3398 仓鼠找 sugar
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3398
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-20 19:40:01 

#include <iostream>

#include <vector>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int Q = 1e5 + 10;

int n, q;
int u, v, f1, f2, a, b, c, d;
int dfn[N], rnk[N];
int fa[N], dep[N];
int siz[N], hson[N];
int top[N], cnt;
vector<int> g[N];

inline void init(int u)
{
    hson[u] = -1; siz[u] = 1;
    dep[u] = dep[fa[u]] + 1;
    for (auto v : g[u])
        if (!dep[v])
        {
        	if (v == fa[u]) continue;
            fa[v] = u; init(v);
            siz[u] += siz[v];
            if (hson[u] == -1 || siz[v] > siz[hson[u]])
                hson[u] = v;
        }
}
inline void cut(int u, int tp)
{
    top[u] = tp; dfn[u] = ++cnt; rnk[cnt] = u;
    if (hson[u] == -1) return;
    cut(hson[u], tp);
    for (auto v : g[u])
        if (v != hson[u] && v != fa[u])
            cut(v, v);
}
inline int LCA(int x, int y)
{
	while (top[x] != top[y])
		dep[top[x]] > dep[top[y]] ? x = fa[top[x]] : y = fa[top[y]];
	return dep[x] < dep[y] ? x : y;
}

int main()	
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	init(1); cut(1, 1);
	for (int i = 1; i <= q; ++i)
	{
		cin >> a >> b >> c >> d;
		f1 = LCA(a, b);
		f2 = LCA(c, d);
		// cerr << f1 << ' ' << f2 << endl;
		cout << ( (dep[f1] <= dep[f2] && (LCA(f2, a) == f2 || LCA(f2, b) == f2))
			   || (dep[f1] >= dep[f2] && (LCA(f1, c) == f1 || LCA(f1, d) == f1))
		? 'Y' : 'N') << endl;
	}
	return 0;
}