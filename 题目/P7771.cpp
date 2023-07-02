// Problem:      P7771 【模板】欧拉路径
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P7771
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-05 18:58:26 

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
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

int m, n, st = 1, ed = 1;
int vis[100010];
int in[100010], out[100010];

bool existS = 0, existE = 0;
bool existR = 1;
int cntS, cntE;

vector<int> g[100010];
vector<int> ans;

void EulerRoad(const int& u)
{
	for (reg int v = vis[u]; v < g[u].size(); v = vis[u])
	{
		vis[u] = v + 1;
		EulerRoad(g[u][v]);
	}
	ans.pb(u);
}

int main()
{
	cin >> n >> m;
	for (reg int i = 1, u, v; i <= m; ++i)
	{
		cin >> u >> v;
		g[u].pb(v);
		++out[u], ++in[v];
	}
	
	for (reg int i = 1; i <= n; ++i)
	{
		if (in[i] - out[i] != 0) existR = 0;
		if (out[i] - in[i] == 1) existS = 1, st = i, ++cntS;
		if (in[i] - out[i] == 1) existE = 1, ed = i, ++cntE;
		if (cntS > 1 || cntE > 1) { printf("No\n"); return 0; }
	}
	
	if ( !(existS && existE) && !existR) { printf("No\n"); return 0; }
	
	for (reg int i = 1; i <= n; ++i) 
		sort(g[i].begin(), g[i].end());
	
	EulerRoad(st);
	reverse(ans.begin(), ans.end());
	for (auto x : ans)
		cout << x << ' ';
	return 0;
}
