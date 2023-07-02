// Problem:      P9234 [蓝桥杯 2023 省 A] 买瓜
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9234
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-15 19:18:09 

// 你甜蜜的劈我瓜是罢

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int inf = 0x7fffffff;

int n, m;
int a[110];
bool spt[110];
int ans = inf;

inline void dfs(int p, int w, int k)
{
	if (w > m || p > n + 1|| k > ans) return;
	if (w == m)
	{
		ans = min(ans, k);
		return;
	}
	dfs(p + 1, w, k);
	dfs(p + 1, w + a[p], k + 1);
	dfs(p + 1, w + a[p] * 2, k);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m; m *= 2;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	dfs(1, 0, 0);
	cout << (ans == inf ? -1 : ans) << endl;
	return 0;
}