// Problem:      P6394 樱花，还有你
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6394
// Memory Limit: 64 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-05 14:30:18 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e3 + 10;
const int mod = 10086001;

int n, k, ans, all;
int s[N], dp[N], sum[N];
// dp[i][j] express the number of ways 
// to collect j flowers under the ith tree.
// now we do not need [i] anymore

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	// changed to collect k flowers under n trees.
	cin >> k >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> s[i], all += s[i];
	
	if (all < k) { cout << "impossible" << endl; return 0; }
	ans += (s[1] >= k);
	for (reg int i = 0; i <= s[1]; ++i)
		sum[i] = i + 1;
	for (reg int i = s[1] + 1; i <= k; ++i)
		sum[i] = sum[i - 1];
	for (reg int i = 2; i <= n; ++i)
	{
		for (reg int j = 0; j <= k; ++j)
		{
			if (j > s[i]) dp[j] = (sum[j] - sum[j - s[i] - 1]) % mod;
			else		  dp[j] = sum[j] % mod;
		}
		sum[0] = dp[0];
		for (reg int j = 1; j <= k; ++j)
			sum[j] = (sum[j - 1] + dp[j]) % mod;
		ans = (ans + dp[k]) % mod;
	}
	cout << (ans + mod) % mod << endl;
	return 0;
}