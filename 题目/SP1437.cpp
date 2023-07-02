// Problem:      PT07Z - Longest path in a tree
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/SP1437
// Memory Limit: 1 MB
// Time Limit:   181000 ms
// Created Time: 2023-03-24 20:57:21 

#include <iostream>

#include <vector>
#include <cstring>

#define i64 long long 
#define qwq puts("fzy qwq ~");
#define pb push_back

using namespace std;

int n, u, v, faq = 1;
vector<int> g[10010];
int dep[10010];

void dfs(int u, int fa)
{
	for (auto v : g[u])
	{
		if (fa == v) continue;
		dep[v] = dep[u] + 1;
		if (dep[v] > dep[faq]) faq = v; 
		dfs(v, u);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		cin >> u >> v;
		g[u].pb(v); g[v].pb(u);
	}
	dfs(1, 0);
	dep[faq] = 0;
	dfs(faq, 0);
	cout << dep[faq] << endl;
	return 0;
}