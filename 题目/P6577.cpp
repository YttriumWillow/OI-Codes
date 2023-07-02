// Problem:      P6577 【模板】二分图最大权完美匹配
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6577
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-23 11:02:46 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int inf = 0x3fffffff;

int n, m;
int u, v, W;
int match[510];
i64 slk[510];
i64 w[510][510];
i64 l[510]; bool visl[510];
i64 r[510]; bool visr[510];

i64 d, ans;

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

inline void bfs(int u)
{
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = 1; j <= n; ++j)
			w[i][j] = -inf;
	for (reg int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> W;
		w[u][v] = W;
	}
	KM();
    for (reg int i = 1; i <= n; ++i)
        ans += w[match[i]][i];
    cout << ans << endl;
    for (reg int i = 1; i <= n; ++i)
    	cout << match[i] << ' ';
    cout << endl;
	return 0;
}


