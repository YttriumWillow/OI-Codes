// Problem:      P9208 虚人「无」
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9208
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-10 19:00:36 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

int n, mod;
int c[300010], v[300010];
int siz[300010];
int dfn[300010], rnk[300010];
i64 dfncnt, ans;
i64 C[300010];
i64 pre[300010], suf[300010];
vector<int> g[300010];

inline void dfs(int u, int fa)
{
	dfn[u] = ++dfncnt; rnk[dfncnt] = u;
	siz[u] = 1; C[u] = c[u];
	for (auto v : g[u])
	{
		if (v == fa) continue;
		dfs(v, u);
		siz[u] += siz[v];
		C[u] = (C[u] * C[v]) % mod;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> mod;
	for (reg int i = 1, u, v; i <= n - 1; ++i)
		cin >> u >> v, g[u].pb(v), g[v].pb(u);
	for (reg int i = 1; i <= n; ++i)
		cin >> c[i];
	for (reg int i = 1; i <= n; ++i)
		cin >> v[i];
		
	dfs(1, 0); pre[0] = suf[n + 1] = 1;
	
	for (reg int i = 1; i <= n; ++i)
		pre[i] = pre[i - 1] * v[rnk[i]] % mod;
	for (reg int i = n; i >= 1; --i)
		suf[i] = suf[i + 1] * v[rnk[i]] % mod;
	for (reg int i = 1; i <= n; ++i)
		ans = (ans + ( pre[dfn[i] - 1] * suf[dfn[i] + siz[i]] % mod ) * C[i] ) % mod; 
		
	cout << ans % mod << endl;
	return 0;
}