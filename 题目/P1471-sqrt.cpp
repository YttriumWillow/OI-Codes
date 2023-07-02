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

int n, m, opt, x, y;
int blk, tot;
int lft[RT], rgt[RT];
double a[N], k;
double tag[N];
double sum[N], sqr[N];

#define bel(i) ((i - 1) / blk + 1)

inline void init(int n)
{
	// blk = (int)sqrt(n);
	blk = (int)pow(n, 0.474);
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

inline void pushdown(int x)
{
	if (tag[x] == 0) return;
	for (int i = lft[x]; i <= rgt[x]; ++i)
	{
		sqr[x] -= a[i] * a[i];
		a[i] += tag[x];
		sum[x] += tag[x];
		sqr[x] += a[i] * a[i];
	}
	tag[x] = 0;
}

inline void modify(int l, int r, double k)
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

inline double qsum(int l, int r)
{
	int L = bel(l), R = bel(r), t = (r - l + 1);
	double res = 0; 
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
	return res / t;
}

inline double query(int l, int r)
{
	int L = bel(l), R = bel(r), t = (r - l + 1);
	double res = 0, ave = 0;
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
	return res / t - (ave / t) * (ave / t);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(4);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	init(n);
	for (int i = 1; i <= m; ++i)
	{
		cin >> opt >> x >> y;
		if (opt == 1)
			cin >> k, modify(x, y, k);
		if (opt == 2)
			cout << qsum(x, y) << endl;
		if (opt == 3)
			cout << query(x, y) << endl;
	}
	return 0;
}