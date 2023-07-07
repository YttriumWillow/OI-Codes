// Problem:      AROPE2 - Alphabetic Rope2
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/SP29458
// Memory Limit: 1 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-05 21:08:47 

#include <iostream>
#include <ext/rope>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;
using namespace __gnu_cxx;

const int N = 1e4 + 10;

int q, opt, x, y;
string s; int ver;
crope h[N], now;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> s >> q;
	h[0].insert(0, s.c_str());
	
	for (int i = 1; i <= q; ++i)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> x >> y;
			h[i] = h[i - 1].substr(x, y - x + 1)
				 + h[i - 1].substr(0, x)
				 + h[i - 1].substr(y + 1, h[i - 1].size() - y - 1);
		}
		if (opt == 2)
		{
			cin >> x >> y;
			h[i] = h[i - 1].substr(0, x)
				 + h[i - 1].substr(y + 1, h[i - 1].size() - y - 1)
				 + h[i - 1].substr(x, y - x + 1);
		}
		if (opt == 3)
		{
			cin >> x; h[i] = h[i - 1];
			cout << h[i][x] << endl;
		}
		if (opt == 4)
		{
			cin >> x >> y; h[i] = h[i - 1];
			cout << h[x][y] << endl;
		}
	}
	return 0;
}