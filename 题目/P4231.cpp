// Problem:      P4231 三步必杀
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4231
// Memory Limit: 250 MB
// Time Limit:   500000 ms
// Created Time: 2023-03-04 13:43:48

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, m, d, ans, xorans;
i64 l, r, s, e;
i64 dif[10000010];
i64 x, y;

int main()
{
    scanf("%lld%lld", &n, &m);
    while (m--)
    {
        scanf("%lld%lld%lld%lld", &l, &r, &s, &e);
        d = (e - s) / (r - l);
        dif[l] += s;
        dif[l + 1] += d - s;
        dif[r + 1] -= d + e;
        dif[r + 2] += e;
    }
    for (reg int i = 1; i <= n; ++i)
        ans = max(ans, y += (x += dif[i])), xorans ^= y;
    printf("%lld %lld\n", xorans, ans);
    return 0;
}