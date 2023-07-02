// Problem:      P5367 【模板】康托展开
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5367
// Memory Limit: 64 MB
// Time Limit:   1200 ms
// Created Time: 2023-03-03 15:29:47

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
// #define lowbit(x) (x & (-x))

using namespace std;

const i64 xhg = 998244353;

i64 n, ans = 1;
int a[1000010];
int t[1000010];
i64 pre[1000010];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int y)
{
    for (reg int i = x; i <= n; i += lowbit(i))
        t[i] += y;
}

int query(int x)
{
    int res = 0;
    for (reg int i = x; i > 0; i -= lowbit(i))
        res += t[i];
    return res;
}

int main()
{
    scanf("%lld", &n);
    pre[0] = 1;
    for (reg int i = 1; i <= n; ++i)
        pre[i] = (pre[i - 1] * i) % xhg, add(i, 1);
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        // printf("[LOG]now:%d ans:%d\n", i, ans);
        ans = (ans + ((query(a[i]) - 1) * pre[n - i]) % xhg) % xhg;
        add(a[i], -1);
    }
    printf("%lld", ans);
    return 0;
}