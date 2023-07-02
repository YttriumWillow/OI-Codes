// Problem:      P2731 [USACO3.3]骑马修栅栏 Riding the Fences
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2731
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-05 16:09:34 

#include <iostream>

#include <algorithm>
#include <vector>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int m, n, start = 1;
int deg[510];
int g[510][510];

vector<int> ans;

void EulerRoad(const int& u)
{
	for (reg int v = 1; v <= n; ++v)
		if (g[u][v])
		{
			--g[u][v], --g[v][u];
			EulerRoad(v);
		}
	ans.insert(ans.begin(), u);
}

int main()
{
	cin >> m;
	for (reg int i = 1, u, v; i <= m; ++i)
	{
		cin >> u >> v;
		n = max({ n, u, v });
		++deg[u], ++deg[v];
		++g[u][v], ++g[v][u];
	}
	for (reg int i = 1; i <= n; ++i)
		if (deg[i] & 1)
			{ start = i; break; }
	EulerRoad(start);
	for (auto x : ans)
		cout << x << endl;
	return 0;
}