// Problem:      P1375 小猫
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1375
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-14 20:48:42 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 mod = 1e9 + 7;

inline i64 fpow(i64 a, i64 k)
{
    i64 res = 1;
    for (; k; k >>= 1)
    {
        if (k & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

inline i64 inv(i64 x) { return fpow(x, mod - 2); }

i64 n;
i64 cat[100010] = { 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (reg int i = 1; i <= n; ++i)
    	cat[i] = cat[i - 1] % mod * (4 * i - 2) % mod * inv(i + 1) % mod;
    cout << cat[n] << endl;
    return 0;
}