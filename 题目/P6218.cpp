// Problem:      P6218 [USACO06NOV] Round Numbers S
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6218
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-12 19:58:01 

#include <iostream>

#include <cstring>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 l, r, cnt;
i64 dp[33][33][33][2][2];
int a[33];

i64 dfs(int n, int zero, int one, bool f1, bool f2) // f1 是否本位最大， f2 是否有前导零
{
	if (n <= 0) return zero >= one;
	if (f2) zero = 0;
	if (dp[n][zero][one][f1][f2] != -1)
		return dp[n][zero][one][f1][f2];

	int m = f1 ? a[n] : 1;
	int ans = 0;
	for (reg int i = 0; i <= m; ++i)
		ans += dfs(n - 1, zero + !(bool)i, one + (bool)i, f1 && (a[n] == i), f2 && !(bool)i);
	return dp[n][zero][one][f1][f2] = ans;
}

i64 solve(i64 n)
{
	cnt = 0;
	memset(dp, -1, sizeof dp);
	while (n)
		a[++cnt] = n % 2, n /= 2;
	return dfs(cnt, 0, 0, 1, 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> l >> r;
	cout << solve(r) - solve(l - 1) << endl;
	return 0;
}