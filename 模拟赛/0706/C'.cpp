#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 4e4 + 5;

int n, m, res;
vector<int> ans;
bool g[N][N];
bool vis[N];

inline void dfs(int u)
{
	vis[u] = 1, ++res;
	for (int i = 1; i <= n; ++ i)
		if (!g[u][i] && !vis[i])
			dfs(i);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			res = 0, dfs(i), ans.push_back(res);
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (auto x : ans)
		cout << x << ' ';
}
