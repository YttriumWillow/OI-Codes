// Problem:      P1403 [AHOI2005]约数研究
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1403
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-21 15:49:13 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n;

i64 f(int n)
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

int main()
{
	cin >> n;
	cout << f(n) << endl;
	return 0;
}