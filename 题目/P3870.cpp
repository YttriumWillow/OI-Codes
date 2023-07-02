// Problem:      P3870 [TJOI2009] 开关
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3870
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-12 19:28:08 

#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~!");

using namespace std;

namespace IO
{
	template<typename Tp>
	inline void read(Tp &x)
	{
		#define gc getchar
		x = 0; char ch = gc(); bool sgn = 0;
		for (; !isdigit(ch); ch = gc()) sgn |= (ch == '-');
		for (; isdigit(ch); ch = gc()) x = (x * 10) + (ch ^ '0');
		x = (sgn ? -x : x);
	}
	template<typename Tp, typename ...Args>
	inline void read(Tp &x, Args& ...args)
	{ read(x), read(args...); }
}
using namespace IO;

int n, m;
int opt, l, r;
int a[100010];

// #define bel(p) ( (p - 1) / blk + 1 )
int blk, tot;
int lft[1010], rgt[1010];
int sum[1010], tag[1010];
int bel[100010];

inline void init(int n)
{
	int blk = (int)sqrt(n);
	int tot = n / blk + (bool)(n % blk);
	for (reg int i = 1; i <= tot; ++i)
	{
		lft[i] = (i - 1) * blk + 1;
		rgt[i] = i * blk;
	} rgt[tot] = n;
	for (reg int i = 1; i <= n; ++i)
		bel[i] = (i - 1) / blk + 1;
}

inline void pushdown(int p)
{
	int res = 0;
	for (reg int i = lft[p]; i <= rgt[p]; ++i)
	{
		a[i] ^= 1;
		res += (a[i] == 1);
	}
	sum[p] = res;
	tag[p] = 0;
}

inline void modify(int l, int r)
{
	int L = bel[l];
	int R = bel[r];
	if (L == R)
	{
		if (tag[L]) pushdown(L);
		for (reg int i = l; i <= r; ++i)
		{
			a[i] ^= 1;
			sum[L] += (a[i] ? 1 : -1);
		}
		return;
	}
	if (tag[L]) pushdown(L);
	if (tag[R]) pushdown(R);
	for (reg int i = l; i <= rgt[L]; ++i)
	{
		a[i] ^= 1;
		sum[L] += (a[i] ? 1 : -1);
	}
	for (reg int i = lft[R]; i <= r; ++i)
	{
		a[i] ^= 1;
		sum[R] += (a[i] ? 1 : -1);
	}
	for (reg int i = L + 1; i <= R - 1; ++i)
	{
		tag[i] ^= 1;
		sum[i] = blk - sum[i];
	}
}

inline int query(int l, int r)
{
	int L = bel[l];
	int R = bel[r];
	int res = 0;
	if (L == R)
	{
		if (tag[L]) pushdown(L);
		for (reg int i = 1; i <= n; ++i)
			res += a[i];
		return res;
	}
	if (tag[L]) pushdown(L);
	if (tag[R]) pushdown(R);
	for (reg int i = l; i <= rgt[L]; ++i)
		res += a[i];
	for (reg int i = lft[R]; i <= r; ++i)
		res += a[i];
	for (reg int i = L + 1; i <= R - 1; ++i)
		res += sum[i];
	return res;
}

int main()
{
	read(n, m); init(n);
	for (reg int i = 1; i <= m; ++i)
	{
		read(opt, l, r);
		if (!opt) modify(l, r);
		else	  printf("%d\n", query(l, r));
	}
	return 0;
}