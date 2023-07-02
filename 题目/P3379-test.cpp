// Problem:      P3379 【模板】最近公共祖先（LCA）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3379
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-06-26 16:02:20 

inline void init(int u)
{
	hson[u] = -1; siz[u] = 1;
	dep[u] = dep[fa[u]] + 1;
	for (auto v : g[u])
	{
		if (!dep[v])
		{
			if (v == fa[u]) continue;
			fa[v] = u; init(v);
			siz[u] += siz[v];
			if (!~hson[u] || siz[v] > siz[hson[u]])
				hson[u] = v;
		}
	}
}

inline void cut(int u, int tp)
{
	top[u] = tp; ++cnt;
	if (!~hson[u]) return;
	cut(hson[u], tp);
	for (auto v : g[u])
		if(v != hson[u] && v != fa[u])
			cut(v, v);
}

inline int LCA(int u, int v)
{
	while (top[u] != top[v])
		(dep[top[u]] > dep[top[v]]) ? u = fa[top[u]] : v = fa[top[v]];
	return dep[u] < dep[v] ? u : v;
}