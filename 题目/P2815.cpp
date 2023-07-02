// Problem:	P2815 IPv6地址压缩
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P2815
// Memory Limit:	125 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-22 20:36:05

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int l, r, len, s = 8, b;
int ipv6[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int zero[3] = {0, 0, 0};

int main()
{
    scanf("%x:%x:%x:%x:%x:%x:%x:%x", &ipv6[1], &ipv6[2], &ipv6[3], &ipv6[4], &ipv6[5], &ipv6[6], &ipv6[7], &ipv6[8]);
    for (reg int i = 8; i >= 0; --i)
        if (!ipv6[i])
            ++l;
        else
        {
            if (l > b)
                b = l, s = i;
            l = 0;
        }
    for (reg int i = 1; i < s; ++i)
        printf("%x:", ipv6[i]);
    if (s != 0)
        printf("%x", ipv6[s]);
    if (s != 8)
    {
        printf("::");
    }
    for (reg int i = s + b + 1; i < 8; ++i)
        printf("%x:", ipv6[i]);
    if (s + b < 8)
        printf("%x", ipv6[8]);
    return 0;
}
