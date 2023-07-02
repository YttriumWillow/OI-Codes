// Problem:      P8601 [蓝桥杯 2013 省 A] 剪格子
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8601
// Memory Limit: 64 MB
// Time Limit:   5000 ms
// Created Time: 2023-02-25 13:54:49

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, sum;
int a[15][15];

int main()
{
    scanf("%d%d", &m, &n);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]), sum += a[i][j];
    if (sum % 2 == 1)
    {
        printf("%d\n", 0);
        return 0;
    }
    
    return 0;
}