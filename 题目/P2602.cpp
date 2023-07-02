// Problem:      P2602 [ZJOI2010] 数字计数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2602
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-11 10:20:10 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 a, b;
i64 l[16], r[161];
i64 dp[16], base[16];

inline void init()
{
	base[0] = 1;
	for (reg int i = 1; i <= 15; ++i)
	{
		dp[i] = dp[i - 1] * 10 + base[i - 1];
		base[i] = base[i - 1] * 10;
	}
}

inline void Dp(i64 n, i64 *ans)
{
	int x[16];
	reg i64 tmp = n;
	reg i64 len = 0;
	while (n)
	{
		x[++len] = n % 10;
		n /= 10;
	}
	for (reg int i = len; i >= 1; --i)
	{
		for (reg int j = 0; j < 10; ++j)
			ans[j] += dp[i - 1] * x[i];
		for (reg int j = 0; j < x[i]; ++j)
			ans[j] += base[i - 1];
		
		tmp -= base[i - 1] * x[i];
		ans[x[i]] += tmp + 1;
		ans[0] -= base[i - 1];
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> a >> b;
	init();
	Dp(b, r), Dp(a - 1, l);
	for (reg int i = 0; i < 10; ++i)
		cout << r[i] - l[i] << ' ';
	return 0;
}