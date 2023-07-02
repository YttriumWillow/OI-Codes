// Problem:      B3717 组合数问题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/B3717
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-03-09 19:52:52

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 p = 998244353;

i64 T, n, m, ans;

template <typename _Tp> inline void read(_Tp &x)
{
#define gc() getchar()
    x = 0;
    char c = gc();
    bool f = 0;
    while (!std::isdigit(c))
        f |= c == 45, c = gc();
    while (std::isdigit(c))
        x = x * 10 + (c ^ 48), c = gc();
    return (void)(f ? x = -x : 1);
}

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    i64 ret = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return ret;
}
i64 inv(i64 a, i64 m)
{
    i64 d, x, y, t = m;
    d = exgcd(a, t, x, y);
    if (d == 1)
        return (x % t + t) % t;
    return -1;
}
i64 C(i64 n, i64 m, i64 p)
{
    i64 a = 1, b = 1;
    if (m > n)
        return 0;
    while (m)
    {
        a = (a * n) % p;
        b = (b * m) % p;
        m--;
        n--;
    }
    return a * inv(b, p) % p;
}
i64 Lucas(i64 n, i64 m, i64 p)
{
    if (m == 0)
        return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
int main()
{
    read(T); read(n);
    while (T--)
    {
        read(n), read(m);
        ans ^= Lucas(n, m, p);
    }
    printf("%lld\n", ans);
    return 0;
}