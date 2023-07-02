// Problem:      巨大的斐波那契数！ Colossal Fibonacci Numbers!
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/UVA11582
// Memory Limit: 0 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-20 13:45:09

// UVA11582
#include <iostream>

#define i64 long long
#define u64 unsigned i64
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int T;

namespace Solution
{
	
u64 a, b;
int n, mod;
int f[1000010] = { 0, 1, 1 };

inline int qpow(u64 a, u64 b, int mod)
{
    a %= mod; u64 res = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
    }
    return res % mod;
}
inline int main()
{
    cin >> a >> b >> n;
    if (n == 1 || a == 0) { cout << 0 << endl; return 0; }
    for (int i = 3; i <= n * n + 4; ++i)
    {
        f[i] = (f[i - 1] + f[i - 2]) % n;
        if (f[i] == 1 && f[i - 1] == 1)
        { mod = i - 2; break; }
    }
    cout << f[qpow(a, b, mod)] << endl;
    return 0;
}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin >> T;
    while (T--)
        Solution::main();
    return 0;
}