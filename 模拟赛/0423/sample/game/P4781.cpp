// Problem:      P4781 【模板】拉格朗日插值
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4781
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-24 18:47:04 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 mod = 998244353;

i64 n, k, ans, u, d;
i64 x[2010], y[2010];

inline i64 fpow(i64 a, i64 p)
{
	i64 base = a, res = 1;
	while (p)
	{
		if (p & 1)
			res = res * base % mod;
		base = base * base % mod;
		p >>= 1;
	}
	return res;
}
inline i64 inv(i64 x) { return fpow(x, mod - 2); }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (reg int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	for (reg int i = 1; i <= n; ++i)
	{
		u = 1; d = 1;
		for (reg int j = 1; j <= n; ++j)
			if (i != j)
			{
				u = u * (k - x[j]) % mod;
				d = d * (x[i] - x[j]) % mod;
			}
		ans = (ans + y[i] * u % mod * inv(d) % mod) % mod;
	}
	cout << (ans % mod + mod) % mod << endl;
	return 0;
}