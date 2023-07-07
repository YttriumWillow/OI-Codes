// Problem:      自带版本控制功能的IDE Version Controlled IDE
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/UVA12538
// Memory Limit: 0 MB
// Time Limit:   3000 ms
// Created Time: 2023-07-05 19:08:41 

#include <iostream>
#include <cstring>
#include <ext/rope>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;
using namespace __gnu_cxx;

const int N = 5e4 + 10;

int q, opt, v, c;
int lst, ver, pos;
crope txt[N], faq;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> q;
	while (q--)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> pos >> s;
			pos -= lst;
			faq.insert(pos, s.c_str());
			txt[++ver] = faq;
		}
		if (opt == 2)
		{
			cin >> pos >> c;
			pos -= lst, c -= lst;
			faq.erase(pos - 1, c);
			txt[++ver] = faq;
		}
		if (opt == 3)
		{
			cin >> v >> pos >> c;
			v -= lst, pos -= lst, c -= lst;
			crope res = txt[v].substr(pos - 1, c);
			lst += count(res.begin(), res.end(), 'c');
			cout << res << endl;
		}
	}
	return 0;
}