// Problem:      P1120 小木棍
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1120
// Memory Limit: 128 MB
// Time Limit:   260000 ms
// Created Time: 2023-03-01 20:40:27

#include <iostream>

#include <algorithm>

// #pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx")

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

template <typename _Tp> inline void read(_Tp &x)
{
    x = 0;
    reg char c = getchar();
    reg bool f = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return (void)(f ? x = -x : 1);
}

int n, ans, sum, num;
int a[71];
bool v[71];

inline bool dfs(int stick, int length, int last)
{
    int fail = 0;
    if (length == ans)
        return dfs(stick + 1, 0, 1);
    if (stick >= num)
        return 1;
    for (reg int i = last; i <= n; ++i)
    {
        if ( (length + a[i] <= ans) && (!v[i]) && (a[i] != fail) )
        {
            v[i] = 1;
            // if (a[i] > ans)
                // return 0;
            if (dfs(stick, length + a[i], i + 1))
                return 1;
            v[i] = 0;
            fail = a[i];
            if ((!length) || length + a[i] >= ans)
                return 0;
        }
    }
    return 0;
}
int main()
{
    read(n);
    for (reg int i = 1; i <= n; ++i)
    {
        read(a[i]);
        sum += a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (ans = a[1]; ans <= sum; ++ans)
    {
        if (sum % ans)
            continue;
        num = sum / ans;
        if (dfs(1, 0, 1))
        {
            printf("%d\n", ans);
            return 0;
        }
    }
    return 0;
}