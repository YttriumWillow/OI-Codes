// Problem:      The Sum of the k-th Powers
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF622F
// Memory Limit: 250 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-26 16:34:45 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 mod = 1e9 + 7;

inline i64 fpow(i64 base, i64 p)
{
	i64 res = 1;
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

i64 n, k;
i64 y, u, d, ans;
i64 pre[1000010];
i64 suf[1000010];
i64 fac[1000010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k; pre[0] = suf[k + 3] = fac[0] = 1;
	
	for (reg int i = 1; i <= k + 2; ++i)
		pre[i] = pre[i - 1] * (n - i) % mod;
	for (reg int i = k + 2; i >= 1; --i)
		suf[i] = suf[i + 1] * (n - i) % mod;
	for (reg int i = 1; i <= k + 2; ++i)
		fac[i] = fac[i - 1] * i	% mod;
		
	for (reg int i = 1; i <= k + 2; ++i)
	{
		y = (y + fpow(i, k)) % mod;
		u = pre[i - 1] * suf[i + 1] % mod;
		d = fac[i - 1] * ((k - i) & 1 ? -1 : 1) * fac[k + 2 - i] % mod;
		ans = ( ans + y * u % mod * inv(d) % mod) % mod;
	}
	
	cout << (ans % mod + mod) % mod << endl;
	return 0;	
}