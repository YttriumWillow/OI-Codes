// Problem:	P2241 统计方形（数据加强版）
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P2241
// Memory Limit:	125 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-24 15:27:56

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint n, m;
longint sqr, rec;

int main()
{
    scanf("%lld%lld", &n, &m);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            if (i == j)
                sqr += (n - i + 1) * (m - j + 1);
            else
                rec += (n - i + 1) * (m - j + 1);

    cout << sqr << ' ' << rec << endl;
    return 0;
}