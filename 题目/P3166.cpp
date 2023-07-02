// Problem:      P3166 [CQOI2014]数三角形
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3166
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-08 19:25:39 

#include <iostream>

#include <algorithm>

#define i64 long long 
#define reg register
#define qwq puts("fzy qwq ~");

#define C(x) (x * (x - 1) * (x - 2) / 6)

using namespace std;

i64 n, m;
i64 ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m; ++n, ++m;
	ans = C(n * m) - m * C(n) - n * C(m);
	for (reg int i = 1; i < n; ++i)
		for (reg int j = 1; j < m; ++j)
			ans -= 2ll * (__gcd(i, j) - 1) * (n - i) * (m - j);
	cout << ans << endl;
	return 0;
}