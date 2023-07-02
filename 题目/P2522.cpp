// Problem:      P2522 [HAOI2011]Problem b
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2522
// Memory Limit: 250 MB
// Time Limit:   2500 ms
// Created Time: 2023-05-18 20:10:48 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 50010;

int T, a, b, c, d, k, tot;
int mu[N], p[N], sum[N];

inline void init(int n)
{
	mu[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!p[i]) p[++tot] = i, mu[i] = -1;
		for (int j = 1; j <= tot && i * p[j] <= n; ++j)
		{
			p[i * p[j]] = 1;
			if (!(i % p[j])) { mu[i * p[j]] = 0; break; }
			mu[i * p[j]] = -mu[i];
		}
	}
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + mu[i];
}

inline i64 calc(int n, int m)
{
	i64 res = 0;
	for (int l = 1, r; l <= min(n, m); l = r + 1)
	{
		r = min(n / (n / l), m / (m / l));
		res += 1ll * (sum[r] - sum[l - 1]) * (1ll * n / (l * k)) * (1ll * m / (l * k));
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T; init(50005);
	while (T--)
	{
		cin >> a >> b >> c >> d >> k;
		cout << calc(b, d) + calc(a - 1, c - 1) - calc(b, c - 1) - calc(a - 1, d) << endl;
	}
	return 0;
}