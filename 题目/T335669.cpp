// Problem:      T335669 Darling's Game
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T335669
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-13 14:55:43 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int inf = 0x7fffffff; // 7 个
const i64 inf = 0x7fffffffffffffff; // 15 个

i64 n0, n2;
i64 ans = -inf;

#define sep(tot) ((n0 - tot + 1) * (n0 - tot + 1) + (tot - 1) - (n2 / (tot + 1)) * (n2 / (tot + 1)) * (tot + 1 - (n2 % (tot + 1))) - ((n2 / (tot + 1)) + 1) * ((n2 / (tot + 1)) + 1) * (n2 % (tot + 1)))

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n0 >> n2;
	ans = (n0 * n0) - (n2 * n2);
	for (reg int i = 1; i <= n0; ++i)
		ans = max(ans, sep(i));
	cout << ans << endl;
	return 0;
}