// Problem:      P1383 高级打字机
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1383
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-05 20:07:24 

#include <iostream>
#include <cstring>
#include <ext/rope>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;
using namespace __gnu_cxx;

const int N = 1e5 + 10;

int q, x, ver;
char opt, ch;
crope txt[N], now;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> q;
	while (q--)
	{
		cin >> opt;
		if (opt == 'T')
		{
			cin >> ch;
			now.pb(ch);
			txt[++ver] = now;
		}
		if (opt == 'U')
		{
			cin >> x; // -=-=-=
			now = txt[ver - x];
			txt[++ver] = now;
		}
		if (opt == 'Q')
		{
			cin >> x;
			cout << now[x - 1] << endl;
		}
	}
	return 0;
}