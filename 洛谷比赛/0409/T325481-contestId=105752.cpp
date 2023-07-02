// Problem:      T325481 时效「月岩笠的诅咒」
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T325481?contestId=105752
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-09 19:37:59 

#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

string a, b;
int posa, posb;

int main()
{
	cin >> a >> b;
	cerr << a << ' ' << b << endl;
	for (reg int i = 0; i < a.size(); ++i)
		if (a[i] == '.') { posa = i + 1; break; }
	for (reg int i = 0; i < b.size(); ++i)
		if (b[i] == '.') { posb = i + 1; break; }
	while (posa < a.size() && posb < b.size())
	{
		if (a[posa] != b[posb]) { cout << "NO" << endl; return 0; }
		++posa, ++posb;
	}
	if (posa == a.size() && posb == b.size()) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	return 0;
}