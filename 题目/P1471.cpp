// Problem:      P1471 方差
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1471
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-26 07:09:51 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

int n, m, opt, x, y;
double a[N], sum[N], k;

inline void modify(int x, int y, double k)
{
	for (int i = x; i <= y; ++i)
		a[i] += k;
	for (int i = x; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i];
}

inline double query(int x, int y)
{
	double bar = (sum[y] - sum[x - 1]) / (y - x + 1), res = 0;
	// cerr << bar << endl;
	for (int i = x; i <= y; ++i)
		res += (bar - a[i]) * (bar - a[i]);
	return res / (y - x + 1);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%lf", &a[i]), sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &opt, &x, &y);
		// if (x > y) swap(x, y);
		switch (opt)
		{
			case 1 : scanf("%lf", &k), modify(x, y, k); break;
			case 2 : printf("%.4lf\n", (sum[y] - sum[x - 1]) * 1.0 / (y - x + 1)); break;
			case 3 : printf("%.4lf\n", query(x, y)); break;
			default : qwq
		}
	}
	return 0;
}