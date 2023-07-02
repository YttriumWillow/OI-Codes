// Problem:      LuoTianyi and the Table
// Contest:      Codeforces
// URL:          https://m1.codeforces.com/contest/1825/problem/B
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-08 21:13:33 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int inf = 0x3fffffff;

int T, n, m;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m; int len = n * m;
		int mx = -inf, smx = -inf, mn = inf, smn = inf;
		for (reg int i = 1, x; i <= len; ++i)
		{
			cin >> x;
			if (x >= mx)
			{ smx = mx; mx = x; }
			else if (x >= smx)
			{ smx = x; }
			if (x <= mn)
			{ smn = mn; mn = x; }
			else if (x <= smn)
			{ smn = x; }
		}
		cerr << mx << ' ' << smx << ' ' << mn << ' ' << smn << endl;
		i64 res1 = (mx - smn) * (min(n, m) - 1) 
				 + (max(n, m) - 1) * min(n, m) * (mx - mn);
		i64 res2 = (smx - mn) * (min(n, m) - 1)
				 + (max(n, m) - 1) * min(n, m) * (mx - mn);
		cout << max(res1, res2) << endl;
	}
	return 0;
}