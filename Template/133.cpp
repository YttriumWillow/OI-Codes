// Problem:      #133. 二维树状数组 1：单点修改，区间查询
// Contest:      LibreOJ
// URL:          https://loj.ac/p/133
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-14 19:01:20 

#include <iostream>

#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx512f,sse4.1,sse4.2,avx2")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

template<typename Tp>
struct BIT2D
{
	#define N 4110
	#define lowbit(x) (x & -x)
	Tp t[N][N] = { 0 }; Tp n = 0, m = 0;
	inline void init(Tp ln, Tp lm) { n = ln, m = lm; }
	inline void modify(Tp x, Tp y, Tp k)
	{
		for (reg int i = x; i <= n; i += lowbit(i))
			for (reg int j = y; j <= m; j += lowbit(j))
				t[i][j] += k;
	}
	inline Tp sum(Tp x, Tp y)
	{
		Tp res = 0;
		for (reg int i = x; i; i -= lowbit(i))
			for (reg int j = y; j; j -= lowbit(j))
				res += t[i][j];
		return res;
	}
	inline Tp query(Tp a, Tp b, Tp c, Tp d)
	{
		return sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1);
	}
};

BIT2D<i64> t;

int n, m;
int opt, x, y, k;
int a, b, c, d;

int main()
{
	scanf("%d%d", &n, &m); t.init(n, m);
	while (~scanf("%d", &opt))
	{
		if (opt == 1)
		{
			scanf("%d%d%d", &x, &y, &k);
			t.modify(x, y, k);
		}
		else if (opt == 2)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			printf("%lld\n", t.query(a, b, c, d));
		}
		else qwq
	}
	return 0;
}