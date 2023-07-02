// Problem:      P5142 区间方差
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5142
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-26 09:50:34 

// Problem:      P1471 方差
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1471
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-26 07:42:29 

#include <iostream>
#include <iomanip>
#include <cmath>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int RT = 1e3 + 10;
const int mod = 1e9 + 7;

int n, m, opt, x, y;
int blk, tot;
int lft[RT], rgt[RT];
i64 a[N], k;
i64 tag[N];
i64 sum[N], sqr[N];

#define bel(i) ((i - 1) / blk + 1)

inline int fpow(int a, int k)
{
	int res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
	}
	return res;
}

#define inv(a) (fpow(a, mod - 2) % mod)

inline void init(int n)
{
	// blk = (int)sqrt(n);
	blk = (int)pow(n, 0.476);
	tot = n / blk + !!(n % blk);
	for (int i = 1; i <= tot; ++i)
	{
		lft[i] = (i - 1) * blk + 1;
		rgt[i] = i * blk;
	} rgt[tot] = n;
	for (int i = 1; i <= tot; ++i)
	{
		for (int j = lft[i]; j <= rgt[i]; ++j)
		{
			sum[i] += a[j];
			sqr[i] += a[j] * a[j];
		}
	}
}

inline void modify(int l, int r, i64 k)
{
	int L = bel(l), R = bel(r);
	if (L == R)
	{
		for (int i = l; i <= r; ++i)
		{
			sum[L] += k;
			sqr[L] += 2 * k * a[i] + k * k;
			a[i] += k;
		}
		return;
	}
	for (int i = l; i <= rgt[L]; ++i)
	{
		sum[L] += k;
		sqr[L] += 2 * k * a[i] + k * k;
		a[i] += k;
	}
	for (int i = L + 1; i <= R - 1; ++i)
		tag[i] += k;
	for (int i = lft[R]; i <= r; ++i)
	{
		sum[R] += k;
		sqr[R] += 2 * k * a[i] + k * k;
		a[i] += k;
	}
}

inline i64 qsum(int l, int r)
{
	int L = bel(l), R = bel(r), t = (r - l + 1);
	i64 res = 0; 
	if (L == R)
	{
		for (int i = l; i <= r; ++i)
			res += (a[i] + tag[L]);
		return res / t;
	}
	for (int i = l; i <= rgt[L]; ++i)
		res += (a[i] + tag[L]);
	for (int i = L + 1; i <= R - 1; ++i)
		res += sum[i] + tag[i] * blk;
	for (int i = lft[R]; i <= r; ++i)
		res += (a[i] + tag[R]);
	return (res * inv(t) % mod + mod) % mod;
}

inline i64 query(int l, int r)
{
	int L = bel(l), R = bel(r), t = (r - l + 1);
	i64 res = 0, ave = 0;
	if (L == R)
	{
		for (int i = l; i <= r; ++i)
		{
			ave += (a[i] + tag[L]);
			res += (a[i] + tag[L]) * (a[i] + tag[L]);
		}
		return res / t - (ave / t) * (ave / t);
	}
	for (int i = l; i <= rgt[L]; ++i)
	{
		ave += (a[i] + tag[L]);
		res += (a[i] + tag[L]) * (a[i] + tag[L]);
	}
	for (int i = L + 1; i <= R - 1; ++i)
	{
		ave += sum[i] + tag[i] * blk;
		res += sqr[i] + 2 * sum[i] * tag[i] + tag[i] * tag[i] * blk;
	}
	for (int i = lft[R]; i <= r; ++i)
	{
		ave += (a[i] + tag[R]);
		res += (a[i] + tag[R]) * (a[i] + tag[R]);
	}
	return (res * inv(t) - (ave * inv(t)) * (ave * inv(t)) % mod + mod) % mod;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	init(n);
	for (int i = 1; i <= m; ++i)
	{
		cin >> opt >> x >> y;
		if (opt == 1)
			modify(x, x, y - a[x]);
		if (opt == 2)
			cout << query(x, y) << endl;
	}
	return 0;
}