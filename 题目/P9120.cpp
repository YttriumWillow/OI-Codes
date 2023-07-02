// Problem:      P9120 [春季测试 2023] 密码锁【民间数据】
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9120?contestId=102679
// Memory Limit: 512 MB
// Time Limit:   2500 ms
// Created Time: 2023-03-08 18:49:49 

#include <iostream>

#include <random>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

namespace Solution
{
	int T, k, n;
	int a[5][10010];
	int turn(int now, int b) { return (now + b) % k + 1; }
	void randSolve() // omg what an excellent solution
	{
		
	}
	void solve()
	{
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);
		cin >> T >> k;
		while (T--)
		{
			cin >> n;
			for (reg int i = 1; i <= k; ++i)
				for (reg int j = 1; j <= n; ++j)
					cin >> a[i][j];
			for (reg int t = 1; t <= TRY; ++t)
				randSolve();
			cout << ans << endl;
		}
	}
}

int main()
{
	Solution::solve();
	return 0;
}