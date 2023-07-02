// Problem:      P9117 [春季测试 2023] 涂色游戏【民间数据】
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9117?contestId=102679
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-06 20:17:16 

#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int T, n, m, q;
int line[2][100010];
int pri[2][100010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		cin >> n >> m >> q;
		for (reg int i = 1, opt, x, c; i <= q; ++i)
		{
			cin >> opt >> x >> c;
			line[opt][x] = c; // 记录对应行列颜色
			// 第一维 [0] 表示行，[1] 表示列
			pri[opt][x] = i; // 记录对应行列优先级
			// 对于多次填涂同一行覆盖即可
			// 对于一个格子被所在行列同时覆盖，比较优先级
		}
		for (reg int i = 1; i <= n; ++i)
		{
			for (reg int j = 1; j <= m; ++j)
				// 对于一个格子被所在行列同时覆盖，比较优先级
				if (pri[0][i] > pri[1][j]) // 优先级比较
					cout << line[0][i] << ' ';
				else
					cout << line[1][j] << ' ';
				// 也可写成
				// cout << line[(pri[0][i] < pri[1][j])]
                // 			   [(pri[0][i] >= pri[1][j] ? i : j)] << ' ';
			cout << endl;
		}
		memset(line, 0, sizeof line);
		memset(pri, 0, sizeof pri);
	}
	return 0;
}