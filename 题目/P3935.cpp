// Problem:      P3935 Calculating
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3935
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-21 15:46:06 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

const int mod = 998244353;

using namespace std;

i64 l, r;

i64 f(i64 n)
{
	i64 l = 1, r = 0, res = 0;
	while (l <= n)
	{
		r = (n / (n / l));
		res = ( res + (r - (l - 1)) * (n / l) ) % mod;
		l = r + 1;
	}
	return res % mod;
}

int main()
{
    cin >> l >> r;
    cout << ((f(r) - f(l - 1) % mod) + mod) % mod << endl;
    return 0;
}