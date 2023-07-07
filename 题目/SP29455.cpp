// Problem:      AROPE - Alphabetic Rope
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/SP29455
// Memory Limit: 1 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-05 21:33:54 

// Problem:      AROPE3 - Alphabetic Rope3
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/SP29461
// Memory Limit: 1 MB
// Time Limit:   2000 ms
// Created Time: 2023-07-05 21:28:06 

#include <iostream>
#include <ext/rope>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;
using namespace __gnu_cxx;

const int N = 1e5 + 10;

int q, opt, x, y;
string s;
crope now, p;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> s >> q;
	now.insert(0, s.c_str());
	
	for (int i = 1; i <= q; ++i)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> x >> y;
			now = now.substr(x, y - x + 1) + now.substr(0, x) + now.substr(y + 1, now.size() - y - 1);
		}
		if (opt == 2)
		{
			cin >> x >> y;
			now = now.substr(0, x) + now.substr(y + 1, now.size() - y - 1) + now.substr(x, y - x + 1);
		}
		if (opt == 3)
		{
			cin >> x;
			cout << now[x] << endl;
		}
	}
	return 0;
}