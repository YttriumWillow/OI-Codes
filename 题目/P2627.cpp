// Problem:      P2627 [USACO11OPEN]Mowing the Lawn G
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2627
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-12 18:53:42 

#include <iostream>

#include <deque>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back
#define df pop_front
#define db pop_back

using namespace std;

i64 n, k, tot, ans = 0x7fffffffffff;
i64 e[100010];
i64 dp[100010];

struct Node { i64 id, val; };

deque<Node> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
    for (reg int i = 1; i <= n; ++i)
    {
        cin >> e[i];
        tot += e[i];
        // sum[i] = sum[i - 1] + e[i];
    }
	// for (reg int i = 1; i <= n; ++i)
		// for (reg int j = max(0, i - k); j <= i; ++j)
			// dp[i] = max(dp[i], dp[j - 1] - sum[j]) + sum[i];
	// cout << dp[n] << endl;
	q.pb({0, 0});
	for (reg int i = 1; i <= n; ++i)
	{
		while (!q.empty() && i - q.front().id - 1 > k)
			q.df();
		dp[i] = q.front().val + e[i];
		while (!q.empty() && dp[i] < q.back().val)
			q.db();
		q.pb({i, dp[i]});
	}
	for (reg int i = n - k; i <= n; ++i)
		ans = min(ans, dp[i]);
	cout << tot - ans << endl;
    return 0;
}