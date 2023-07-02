#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, m, p;

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
        m--; n--;
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
    int T;
    cin >> T;
    while (T--)
    {
        scanf("%lld%lld%lld", &n, &m, &p);
        printf("%lld\n", Lucas(n + m, m, p));
    }
    return 0;
}