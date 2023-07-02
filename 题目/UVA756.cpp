// Problem:      Biorhythms
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/UVA756
// Memory Limit: 0 MB
// Time Limit:   3000 ms
// Created Time: 2023-04-07 16:27:05 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 p, e, i, d, ans, cnt;

int main()
{
	while (scanf("%lld%lld%lld%lld", &p, &e, &i, &d) != EOF)
	{
		if (p == -1) return 0;
		++cnt; ans = (p * 5544 + e * 14421 + i * 1288 - d + 21252) % 21252;
		if (ans == 0) ans = 21252;
		// cerr << p << ' ' << e << ' ' << i << ' ' << d << endl;
		printf("Case %d: the next triple peak occurs in %d days.\n", cnt, ans);
	}
	return 0;
}