// Problem:      P5136 sequence
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5136
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-04 15:32:24

#include <iostream>

#include <cmath>
#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int order = 2;
const i64 mod = 998244353;

i64 n, T;

struct Matrix
{
    i64 m[order + 1][order + 1] = { 0 };
    void init() { memset(m, 0, sizeof(m)); }
    friend Matrix operator*(const Matrix &A, const Matrix &B)
    {
        Matrix res;
        for (reg int i = 1; i <= order; ++i)
            for (reg int j = 1; j <= order; ++j)
                for (reg int k = 1; k <= order; ++k)
                    res.m[i][j] = (res.m[i][j] + (A.m[i][k] * B.m[k][j]) % mod) % mod;
        return res;
    }
} base, ans;

inline i64 MatrixQuickPow(i64 p)
{
    i64 f = (p -= 2) & 1;
    while (p)
    {
        if (p & 1)
            ans = ans * base;
        base = base * base;
        p >>= 1;
    }
    return (ans.m[1][1] + f) % mod;
}

void init()
{
    ans.init();
    base.init();

    ans.m[1][1] = 3, ans.m[1][2] = 1;
    ans.m[2][1] = 0, ans.m[2][2] = 0;

    base.m[1][1] = 1, base.m[1][2] = 1;
    base.m[2][1] = 1, base.m[2][2] = 0;
}

int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld", &n);
        if (n <= 2)
        {
            printf("%lld\n", n + 1);
            continue;
        }
        init();
        printf("%lld\n", MatrixQuickPow(n));
    }
    return 0;
}