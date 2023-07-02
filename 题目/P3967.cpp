// Problem:      P3967 [TJOI2014]匹配
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3967
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-23 12:47:29 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int inf = 0x3fffffff;

int n, m, d;
int match[510];
int slk[510];
int w[510][510];
int l[510]; bool visl[510];
int r[510]; bool visr[510];
int ans;

inline bool dfs(int u)
{
	visl[u] = 1;
	for (reg int v = 1; v <= n; ++v)
	{
		if (visr[v]) continue;
		if (l[u] + r[v] == w[u][v])
		{
			visr[v] = 1;
			if (!match[v] || dfs(match[v]))
				return match[v] = u, 1;
		}
		else slk[v] = min(slk[v], l[u] + r[v] - w[u][v]);
	}
	return 0;
}

inline void KM()
{
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = 1; j <= n; ++j)
			l[i] = max(l[i], w[i][j]);
	for (reg int i = 1; i <= n; ++i)
	{
		fill(slk + 1, slk + n + 1, inf);
		while (1)
		{ 
			fill(visl + 1, visl + n + 1, 0);
			fill(visr + 1, visr + n + 1, 0);
			d = inf;
			if (dfs(i)) break;
			for (reg int j = 1; j <= n; ++j)
				if (!visr[j])
					d = min(d, slk[j]);
			for (reg int j = 1; j <= n; ++j)
			{
				if (visl[j]) l[j] -= d;
				if (visr[j]) r[j] += d;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1, u, v, W; i <= m; ++i)
	{
		cin >> u >> v >> W;
		w[u][v] = max(w[u][v], W);
	}
	KM();
    for (reg int i = 1; i <= n; ++i)
        ans += w[match[i]][i];
    cout << ans << endl;
    for (reg int i = 1; i <= n; ++i)
    	cout << i << ' ' << match[i] << "\n";
	return 0;
}

