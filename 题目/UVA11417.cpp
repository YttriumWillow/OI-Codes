// Problem:      GCD
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/UVA11417
// Memory Limit: 0 MB
// Time Limit:   2000 ms
// Created Time: 2023-03-31 18:52:28 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, T, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin >> n)
	{
		if (n == 0) break;
		ans = 0;
		for (reg int i = 1; i <= n; ++i)
			for (reg int j = i + 1; j <= n; ++j)
				ans += __gcd(i, j);
		cout << ans << endl;
	}
	return 0;
}