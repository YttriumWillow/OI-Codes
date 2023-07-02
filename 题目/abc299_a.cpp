// Problem:      A - Treasure Chest
// Contest:      AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2023（AtCoder Beginner Contest 299)
// URL:          https://atcoder.jp/contests/abc299/tasks/abc299_a
// Memory Limit: 1024 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-22 20:21:42 

#include <iostream>

#include <cstring>

#pragma GCC optimize(2)

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

string str;
int p, t;
int pos[3];

int main()
{
	cin >> t;
	cin >> str;
	for (reg int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '|')
			pos[p++] = i;
		if (str[i] == '*')
			pos[2] = i;
	}
	if (pos[0] < pos[2] && pos[2] < pos[1])
		cout << "in" << endl;
	else
		cout << "out" << endl;
	return 0;
}