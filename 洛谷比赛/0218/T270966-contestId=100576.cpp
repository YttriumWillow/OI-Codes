// Problem:	T270966 「SvR-2」令人为难的区间操作问题
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/T270966?contestId=100576
// Memory Limit:	128 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-18 14:04:37

#include <iostream>

#include <cmath>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, T;
longint a;
int cnta;
longint b;
int cntb;

template <typename _Tp> inline void read(_Tp &x)
{
    x = 0;
    char c = getchar();
    bool f = 0;
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        x = x * 10 + (c ^ 48), c = getchar();
    return (void)(f ? x = -x : 1);
}

int main()
{
    read(T);
    while (T--)
    {
        read(n);
        cnta = cntb = 0;
        for (reg int i = 1; i <= n; ++i)
        {
            read(a);
            if (a % 2)
                ++cnta;
        }
        for (reg int i = 1; i <= n; ++i)
        {
            read(b);
            if (b % 2)
                ++cntb;
        }
        abs(cnta - cntb) % 2 ? puts("1") : puts("0");
    }
    return 0;
}