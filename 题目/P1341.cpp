// Problem:      P1341 无序字母对
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1341
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-05 19:14:53 

#include <iostream>

#include <algorithm>
#include <vector>
#include <cstring>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int m, n, st = 1, cntS;
int deg[510];
int g[510][510];

string tb = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

vector<int> ans;

inline int zip(char x)
{
	if ('A' <= x && x <= 'Z')
		return x - 'A' + 1;
	return x - 'a' + 27;
}

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
		char x, y;
		cin >> x >> y;
		u = zip(x); v = zip(y);
		
		// cerr << u << ' ' << v << endl;
		
		n = max({ n, u, v });
		++deg[u], ++deg[v];
		++g[u][v], ++g[v][u];
	}
	
	// cerr << n << endl;
	// for (reg int i = 1; i <= n; ++i)
		// cerr << deg[i] << " \n"[i == 26 || i == n];
	// for (reg int i = 1; i <= n; ++i)
		// for (reg int j = 1; j <= n; ++j)	
			// cerr << g[i][j] << " \n"[j == n];
		
	for (reg int i = 1; i <= n; ++i)
		if (deg[i] & 1) { ++cntS; }
	
	if ( !(cntS == 2 || cntS == 0) ) { printf("No Solution\n"); return 0; }
	
	// 1
	if (cntS == 0)
	{
		for (reg int i = 1; i <= n; ++i)	
			if (deg[i] != 0)
				{ st = i; break; }
	}
	else
	{
		for (reg int i = 1; i <= n; ++i)	
			if (deg[i] & 1)
				{ st = i; break; }
	}
	
	// 2
	if (cntS == 0)
		for (reg int i = 1; i <= n; ++i)	
			if (deg[i] != 0)
				{ st = i; break; }
	else
		for (reg int i = 1; i <= n; ++i)	
			if (deg[i] & 1)
				{ st = i; break; }
	
	EulerRoad(st);
	for (auto x : ans)
		cout << tb[x];
	return 0;
}