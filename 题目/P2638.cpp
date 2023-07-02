// Problem:	P2638 安全系统
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P2638
// Memory Limit:	128 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-24 14:37:21

#include <iostream>

#define i128 __int128
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i128 C[51][51];
i128 a, b, n;
i128 ans;

template <typename _Tp> inline void read(_Tp &x)
{
    x = 0;
    char c = getchar();
    bool f = 0;
    while (!std::isdigit(c))
        f |= c == '-', c = getchar();
    while (std::isdigit(c))
        x = x * 10 + (c ^ 48), c = getchar();
    return (void)(f ? x = -x : 1);
}

template <typename _Tp> inline void write(_Tp x)
{
    static char stk[20];
    int top = 0;
    if (!x)
        return (void)putchar(48);
    if (x < 0)
        putchar(45), x = -x;
    while (x)
        stk[top++] = x % 10, x /= 10;
    while (top)
        putchar(stk[--top] + 48);
}

int main()
{
    read(n); read(a); read(b);

    for (reg int i = 1; i <= 50; ++i)
        C[i][0] = C[i][i] = 1;

    for (reg int i = 1; i <= 50; ++i)
        for (reg int j = 1; j < i; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];

    // cout << C[4][3] << endl;
    // for (reg int i = 0; i <= 50; ++i)
    // {
    // for (reg int j = 0; j < i; ++j)
    // cout << C[i][j] << ' ';
    // cout << endl;
    // }

    for (reg i128 i = 0; i <= a; ++i)
        for (reg i128 j = 0; j <= b; ++j)
            // printf("C[%u][%u]=%u, C[%u][%u]=%u\nmul=%u, ans=%u\n",
            // n + i - 1, n - 1, C[n + i - 1][n - 1],
            // n + j - 1, n - 1, C[n + j - 1][n - 1],
            // C[n + i - 1][n - 1] * C[n + j - 1][n - 1], ans),
            ans += C[n + i - 1][n - 1] * C[n + j - 1][n - 1];
    write(ans);
    return 0;
}