// Problem:      P3390 【模板】矩阵快速幂
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3390
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-02-25 09:41:52

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 mod = 1000000007;

i64 n, k;

struct Matrix
{
    i64 a[110][110];
    friend Matrix operator*(const Matrix A, const Matrix B)
    {
        Matrix ans;
        for (reg int i = 1; i <= n; ++i)
            for (reg int j = 1; j <= n; ++j)
                ans.a[i][j] = 0;
        for (reg int i = 1; i <= n; ++i)
            for (reg int j = 1; j <= n; ++j)
                for (reg int k = 1; k <= n; ++k)
                    ans.a[i][j] = (ans.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;
        return ans;
    }
} A, base;

int main()
{
    scanf("%lld%lld", &n, &k);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n; ++j)
            scanf("%lld", &A.a[i][j]);

    for (reg int i = 1; i <= n; ++i)
        base.a[i][i] = 1;
    while (k > 0)
    {
        if (k % 2 == 1)
            base = base * A;
        A = A * A;
        k = k >> 1;
    }
    for (reg int i = 1; i <= n; ++i)
    {
        for (reg int j = 1; j <= n; ++j)
            printf("%lld ", base.a[i][j]);
        printf("\n");
    }
    return 0;
}