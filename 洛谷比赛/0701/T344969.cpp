// Problem:      T344969 『XYGOI round1』一些数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T344969?contestId=113611
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-01 14:36:32 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

cosnt int

int T, n, q;
int x, y;

inline int checker()
{
	static int dp[N], res;
	dp[1] = a[1]; res = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (dp[res] >= a[i]) dp[++res] = a[i];
		else *upper_bound(da + 1, da + res + 1, a[i]) = a[i];
	}
	return res;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		cin >> n >> q;
		for (int i = 1; i <= n; ++i)
			cin >> x >> y, a[x] = y;
		
		clear();
	}
	return 0;
}