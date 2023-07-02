// Problem:      P4450 双亲数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4450
// Memory Limit: 62 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-18 20:43:11 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1000010;

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
	
	init(1000010);
	cin >> a >> b >> k;
	cout << calc(a, b) << endl;
	return 0;
}