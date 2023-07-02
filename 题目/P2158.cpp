// Problem:      P2158 [SDOI2008] 仪仗队
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2158
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-02-25 13:34:27

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, ans;
i64 f[40010];

i64 Euler(i64 x)
{
    i64 res = 0;
    if (f[x] != 0)
        return f[x];
    for (reg i64 i = 1; i <= n; ++i)
    {
        if (!(x % i) && f[i] != 0 && f[x / i] != 0 && __gcd(i, x / i) == 1)
            return f[x] = f[i] * f[x / i];
        else if (__gcd(x, i) == 1)
            ++res;
    }
    return f[x] = res;
}

// i64 Euler(i64 x)
// {
    // i64 sum = x;
    // for (int i = 2; i * i <= x; ++i)
        // if (x % i == 0)
        // {
            // sum -= sum / i;
            // while (x % i == 0)
                // x /= i;
        // }
    // if (x > 1)
        // sum -= sum / x;
    // return sum;
// }

int main()
{
    scanf("%lld", &n);
    if (n == 1)
    {
        printf("%d\n", 0);
        return 0;
    }
    for (reg int i = 2; i < n; ++i)
        ans += Euler(i),
        printf("[DATA] Phi(%d)=%d\n", i, Euler(i));
    printf("%lld\n", ans * 2 + 3);
    return 0;
}