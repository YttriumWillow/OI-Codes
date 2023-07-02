// Problem:	P1464 Function
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P1464
// Memory Limit:	125 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-24 16:33:47

#include <iostream>

#define i64 long long
#define ui64 unsigned long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 inf = -114514191810;

i64 n, a, b, c;
i64 v[21][21][21];

inline i64 f(i64, i64, i64);
inline i64 query(i64, i64, i64);

inline i64 query(i64 a, i64 b, i64 c)
{
    if (v[a][b][c] == inf)
        v[a][b][c] = f(a, b, c);
    return v[a][b][c];
}

inline i64 f(i64 a, i64 b, i64 c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return query(20, 20, 20);
    else if (a < b && b < c)
        return query(a, b, c - 1) + query(a, b - 1, c - 1) - query(a, b - 1, c);
    else
        return query(a - 1, b, c) + query(a - 1, b - 1, c) + query(a - 1, b, c - 1) - query(a - 1, b - 1, c - 1);
}

int main()
{
    for (reg int i = 0; i <= 20; ++i)
        for (reg int j = 0; j <= 20; ++j)
            for (reg int k = 0; k <= 20; ++k)
                v[i][j][k] = inf;
    while (scanf("%lld%lld%lld", &a, &b, &c) != EOF)
    {
        if (a == -1 && b == -1 && c == -1)
            return 0;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, f(a, b, c));
    }
    return 0;
}