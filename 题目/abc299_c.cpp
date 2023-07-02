// Problem:      C - Dango
// Contest:      AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2023（AtCoder Beginner Contest 299)
// URL:          https://atcoder.jp/contests/abc299/tasks/abc299_c
// Memory Limit: 1024 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-22 20:40:29 

#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

string str;
int n, ans, cnt;
char ch; bool ext;

int main()
{
	cin >> n;
	cin >> str;
	for (reg int i = 0; i < str.size(); ++i)
	{
		if (i != 0)
			if (str[i] == '-' && str[i - 1] == 'o')
				ext = 1;
		if (str[i] == 'o')
			++cnt;
		if (str[i] == '-')
			ans = max(ans, cnt), cnt = 0;
	}
	if (ext)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}