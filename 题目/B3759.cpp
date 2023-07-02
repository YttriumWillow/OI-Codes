// Problem:      B3759 [信息与未来 2021] 文本分类
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/B3759
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-23 08:33:28 

#include <iostream>

#include <cstring>

#define reg register
#define i64 long long
#define qwq puts("fzy qwq ~");

using namespace std;

string str;
int n, T;
bool flag;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n; flag = false;
		for (reg int i = 1; i <= n; ++i)
		{
			cin >> str;
			if (str.find("th") != string::npos)
				flag = true;
		}
		cout << (flag ? "English" : "Pinyin") << endl;
	}
	return 0;
}