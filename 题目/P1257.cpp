// Problem:      P1257 平面上的最接近点对
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1257
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-28 20:11:47

#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, x[10009], y[10009];
double ans = 1145141919810;

int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = i + 1; j <= n; ++j)
        	ans = min( ans, hypot( x[i] - x[j], y[i] - y[j] ) );
    printf("%.4lf", ans);
    return 0;
}
