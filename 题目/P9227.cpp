// Problem:      P9227 异或积
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9227
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-22 19:25:16

#include <iostream>

#define uint unsigned int
#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int T;
u64 n, k, all1, all2;
u64 a[100010];
u64 b1[100010];
u64 b2[100010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> n >> k; all1 = all2 = 0;
        for (reg int i = 1; i <= n; ++i)
            cin >> a[i], all1 ^= a[i];

        for (reg int i = 1; i <= n; ++i)
        {
            b1[i] = 0;
            b1[i] = all1 ^ a[i];
            all2 ^= b1[i];
        }
        for (reg int i = 1; i <= n; ++i)
        {
        	b2[i] = 0;
        	b2[i] = all2 ^ b1[i];
        }
        if (k & 1)
        {
       		for (reg int i = 1; i <= n; ++i)
         	   cout << b1[i] << " \n"[i == n];
        }
        else
        {
       		for (reg int i = 1; i <= n; ++i)
         	   cout << b2[i] << " \n"[i == n];
        }
    }
    return 0;
}