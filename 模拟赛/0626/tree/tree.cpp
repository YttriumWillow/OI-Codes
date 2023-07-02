#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx2,avx512f,popcnt,sse4.1,sse4.2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <iostream>

#include <algorithm>
#include <vector>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

int n, m, k;
int u, v;
int dis[N];
bool vis[N];
i64 ans;

vector<int> g[N];

inline void dfs(int u, int dep)
{
	dis[u] = dep; vis[u] = 1;
	for (auto v : g[u])
		if (!vis[v])
			dfs(v, dep + 1);
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n - 1; ++i)
	{
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 1; i <= n; ++i)
	{
		fill(vis + 1, vis + n + 1, 0);
		fill(dis + 1, dis + n + 1, 0);
		dfs(i, 0);
		for (int j = i + 1; j <= n; ++j)
			ans += (dis[j] / k + !!(dis[j] % k));
	}
	cout << ans << endl;
	return 0;
}