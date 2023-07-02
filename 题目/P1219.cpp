// Problem:	P1219 [USACO1.5]八皇后 Checker Challenge
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P1219
// Memory Limit:	125 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-18 12:34:48

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, sum;
int ans[14], check[3][28] = {0};

void queen(int line)
{
    if (line > n)
    {
        sum++;
        if (sum > 3)
            return;
        else
        {
            for (int i = 1; i <= n; ++i)
                printf("%d ", ans[i]);
            printf("\n");
            return;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if ((!check[0][i]) && (!check[1][line + i]) && (!check[2][line - i + n]))
        {
            ans[line] = i;
            check[0][i] = 1;
            check[1][line + i] = 1;
            check[2][line - i + n] = 1;
            queen(line + 1);
            check[0][i] = 0;
            check[1][line + i] = 0;
            check[2][line - i + n] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    queen(1);
    printf("%d\n", sum);
    return 0;
}
