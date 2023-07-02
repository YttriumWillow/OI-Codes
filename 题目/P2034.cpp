// Problem:      P2034 选择数字
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2034
// Memory Limit: 125 MB
// Time Limit:   500000 ms
// Created Time: 2023-05-17 14:55:33 

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
    }
	q.pb({0, 0});
	for (reg int i = 1; i <= n; ++i)
	{
		while (!q.empty() && i - q.front().id - 1 > k)
			q.pop_front();
		dp[i] = q.front().val + e[i];
		while (!q.empty() && dp[i] < q.back().val)
			q.pop_back();
		q.pb({ i, dp[i] });
	}
	for (reg int i = n - k; i <= n; ++i)
		ans = min(ans, dp[i]);
	cout << tot - ans << endl;
    return 0;
}