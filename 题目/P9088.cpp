// Problem:      P9088 「SvR-2」1+2=3
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9088
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-05 19:50:50 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int main()
{
	cin >> T;
	while (T--)
	{
		init();
		cin >> g[0][0] >> g[0][1] >> g[0][2];
		cin >> g[1][0] >> g[1][1] >> g[1][2];
		cin >> g[2][0] >> g[2][1] >> g[2][2];
		
		out[0] = g[0][0] + g[0][1] + g[0][2];
		out[1] = g[1][0] + g[1][1] + g[1][2];
		out[2] = g[2][0] + g[2][1] + g[2][2];
		
		
	}
	return 0;
}