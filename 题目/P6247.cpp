// Problem:      P6247 [SDOI2012]最近最远点对
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6247
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-25 19:01:17 

#include <iostream>

#include <cmath>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","avx512f","sse4.1","sse4.2")

using namespace std;

struct Node
{
	double x, y;
	inline friend bool operator < (const Node& _x, const Node& _y)
	{ return _x.x < _y.x; }
} a[100010];

int n;
double wtf = -1;
double ans = 1145141919810;

#define dis(p, q) (hypot(a[p].x - a[q].x, a[p].y - a[q].y))

int main()
{
	scanf("%d", &n);
	for (reg int i = 1; i <= n; ++i)
		scanf("%lf %lf", &a[i].x, &a[i].y);
	sort(a + 1, a + n + 1);
	for (reg int i = 1; i <= n; ++i)
	{
		for (reg int j = i + 1; j <= i + 2 && j <= n; ++j)
			ans = min(ans, dis(i, j));
		for (reg int j = n; j >= n - 12 && j > i; --j)
			wtf = max(wtf, dis(i, j));
	}
	printf("%.3lf %.3lf\n", ans, wtf);
	return 0;
}