// Problem:      P3859 [TJOI2008]小偷
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3859
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-29 08:06:44 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, ans;
int cl[51];
int dp[50010];
int r[110], t[110], v[110];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 0; i < n; ++i)
		cin >> cl[i];
	for (reg int i = 1; i <= n; ++i)
		cl[i] = min(cl[i], cl[i - 1]);
	// 9tm6
	for (reg int i = 1; i <= m; ++i)
		cin >> r[i] >> v[i] >> t[i];
	for (reg int i = 1; i < cl[0]; ++i)
	{
		dp[i] = dp[i - 1];
		for (reg int j = 1; j <= m; ++j)
		{
			if (t[j] <= i && i < cl[r[j]])
				if (i >= t[j])
					dp[i] = max(dp[i], dp[i - t[j]] + v[j]);
		}
	}
	cout << dp[cl[0] - 1] << endl;
	return 0;
}