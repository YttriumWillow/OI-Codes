// Problem:      P4593 [TJOI2018]教科书般的亵渎
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4593
// Memory Limit: 250 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-26 19:06:21 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 mod = 1e9 + 7;

i64 T, k, n, m, ans;
i64 a[55], u, d;
i64 fac[55], f[55];
i64 pre[55], suf[55];

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
inline i64 lagrange(int n)
{
	if (n <= k) return f[n];
	suf[k + 1] = 1; i64 res = 0, y = 0, u = 0, d = 0;
	for (reg int i = 1; i <= k; ++i)
		pre[i] = pre[i - 1] * (n - i) % mod;
	for (reg int i = k; i >= 1; --i)
		suf[i] = suf[i + 1] * (n - i) % mod;
	for (reg int i = 1; i <= k; ++i)
	{
		u = pre[i - 1] * suf[i + 1] % mod;
		d = ((k - i) & 1 ? -1 : 1) * fac[i - 1] * fac[k - i] % mod;
		res = ( res + f[i] * u % mod * inv(d) % mod) % mod;
	}
	return (res % mod + mod) % mod;
}
inline void init()
{
	pre[0] = fac[0] = f[1] = 1;
	for (reg int i = 1; i <= 55; ++i)
		fac[i] = fac[i - 1] * i	% mod;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T; init();
	while (T--)
	{
		cin >> n >> m; k = m + 3; ans = 0;
		for (reg int i = 1; i <= m; ++i)
			cin >> a[i];
		sort(a + 1, a + m + 1);
		while (a[m] == n) { --m; --n; --k;}
		for (reg int i = 2; i <= k; ++i)
			f[i] = (f[i - 1] + fpow(i, m + 1)) % mod;
		for (reg int i = 1; i <= m + 1; ++i)
		{
			ans = (ans + lagrange(n - a[i - 1])) % mod;
			i64 t = 0;
			for (reg int j = i; j <= m; ++j)
				t = t + fpow(a[j] - a[i - 1], m + 1);
			ans = (ans + mod - t) % mod;
		}
		cout << (ans % mod + mod) % mod << endl; ans = 0;
	}
	return 0;
}

