// Problem:      棋盘覆盖
// Contest:      AcWing
// URL:          https://www.acwing.com/problem/content/374/#
// Memory Limit: 64 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-16 21:10:54 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m;
pair<int, int> match[110];
bool g[110][110], st[110][110];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1, x, y; i <= m; ++i)
	{
		cin >> x >> y;
		g[x][y] = 1;
	}
	
	return 0;
}