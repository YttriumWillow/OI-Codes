// Problem:	P1706 全排列问题
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P1706
// Memory Limit:	125 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-24 15:46:23

#include <iostream>

#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;
int a[10010];

int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
        a[i] = i;
    for (reg int i = 1; i <= n; ++i)
        printf("%5d", a[i]);
    printf("\n");
    while (next_permutation(a + 1, a + n + 1))
    {
        for (reg int i = 1; i <= n; ++i)
            printf("%5d", a[i]);
        printf("\n");
    }
    return 0;
}