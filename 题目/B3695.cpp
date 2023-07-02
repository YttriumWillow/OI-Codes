// Problem:      B3695 集合运算 3
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/B3695
// Memory Limit: 512 MB
// Time Limit:   500000 ms
// Created Time: 2023-03-03 16:44:04

#include <iostream>

#include <bitset>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, q, op, x, y;
int c[30010];
bitset<30010> s[30010];

void Add(int x, int y)
{
    s[x] <<= y;
    s[x] &= s[0];
}

void Minus(int x, int y)
{
    s[x] >>= y;
    s[x] &= s[0];
}

int And(int x, int y)
{
    return (s[x] & s[y]).count();
}

int Or(int x, int y)
{
    return (s[x] | s[y]).count();
}

int FK(int x, int y)
{
    // bitset<30010> p1 = s[y].flip(), p2 = s[x].flip();
    return (s[x] ^ s[y]).count();
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; ++i)
        s[0].set(i, 1);
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%d", &c[i]);
        for (reg int j = 1; j <= c[i]; ++j)
            scanf("%d", &x), s[i].set(x, true);
    }
    while (q--)
    {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1)
            Add(x, y);
        else if (op == 2)
            Minus(x, y);
        else if (op == 3)
            printf("%d\n", And(x, y));
        else if (op == 4)
            printf("%d\n", Or(x, y));
        else
            printf("%d\n", FK(x, y));
    }
    return 0;
}