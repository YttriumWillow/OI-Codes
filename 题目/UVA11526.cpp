// Problem:      H(n)
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/UVA11526
// Memory Limit: 0 MB
// Time Limit:   5000 ms
// Created Time: 2023-03-31 20:09:58 

#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 H(i64 n)
{
	i64 l = 1, r = 0, res = 0;
	while (l <= n)
	{
		r = (n / (n / l));
		res += (r - (l - 1)) * (n / l);
		l = r + 1;
	}
	return res;
}

i64 n, T;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		cout << H(n) << endl;
	}
	return 0;
}