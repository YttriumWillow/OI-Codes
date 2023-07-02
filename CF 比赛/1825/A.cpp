// Problem:      LuoTianyi and the Palindrome String
// Contest:      Codeforces
// URL:          https://m1.codeforces.com/contest/1825/problem/A
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-08 20:07:54 

#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int check(string s)
{
	int len = s.size(); bool flg = 0;
	for (reg int i = 1; i < len; ++i)
		if (s[i] != s[i - 1])
			flg = 1;
	
	for (reg int i = 0; (i + i) < len; ++i)
		if (s[i] != s[len - i - 1])
			return 0;
	if (flg) return 1;
	else	return 2;
}

int T;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		cin >> s;
		int stt = check(s);
		if (stt == 0) cout << s.size() << endl;
		if (stt == 1) cout << s.size() - 1 << endl;
		if (stt == 2) cout << -1 << endl;
	}
	return 0;
}