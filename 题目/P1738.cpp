// Problem:      P1738 洛谷的文件夹
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1738
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-05 20:48:35 

#include <iostream>

#include <set>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;
string path, dir;
set<string> root; 

int main()
{
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
	{
		cin >> path; dir = "";
		for (reg int j = 0; j < path.size(); ++j)
		{
			if (path[j] == '/')
				root.insert(dir);
			dir += path[j];
		}
		root.insert(dir);
		cout << root.size() - 1 << endl;
	}
	return 0;
}