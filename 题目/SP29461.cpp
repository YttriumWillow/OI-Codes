// Problem:      AROPE3 - Alphabetic Rope3
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/SP29461
// Memory Limit: 1 MB
// Time Limit:   2000 ms
// Created Time: 2023-07-06 07:10:40 

#include <iostream>
#include <ext/rope>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;
using namespace __gnu_cxx;

int q, opt, x, y, n;
string s;
crope a, b;

int main()	
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> s >> q;
	
	n = s.size();
	a.insert(0, s.c_str());
	reverse(s.begin(), s.end());
	b.insert(0, s.c_str());
	
	while (q--)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> x >> y;
			crope tmp = a.substr(x, y - x + 1);
			a = b.substr(n - y - 1, y - x + 1)
              + a.substr(0, x)
              + a.substr(y + 1, n - y - 1);
			b = b.substr(0, n - y - 1)
				+ b.substr(n - x, x)
				+ tmp;
		}
		if (opt == 2)
		{
			cin >> x >> y;
			crope tmp = a.substr(x, y - x + 1);
            a = a.substr(0, x)
              + a.substr(y + 1, n - y - 1)
              + b.substr(n - y - 1, y - x + 1);
            b = tmp
              + b.substr(0, n - y - 1)
              + b.substr(n - x, x);
		}
		if (opt == 3)
		{
			cin >> x;
			cout << a[x] << endl;
		}
	}
	return 0;
}