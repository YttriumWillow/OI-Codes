// Problem:      B - Trick Taking
// Contest:      AtCoder - Tokio Marine & Nichido Fire Insurance Programming Contest 2023（AtCoder Beginner Contest 299)
// URL:          https://atcoder.jp/contests/abc299/tasks/abc299_b
// Memory Limit: 1024 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-22 20:31:29 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, t, p;
int color[200010];
int rnk[200010];
int ans, now;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> t;
	for (reg int i = 1; i <= n; ++i)
		cin >> color[i], p += (color[i] == t);
	for (reg int i = 1; i <= n; ++i)
		cin >> rnk[i];
	if (p)
	{
		for (reg int i = 1; i <= n; ++i)
			if (color[i] == t)
				if (rnk[i] > now)
				{
					ans = i;
					now = rnk[i];
				}
	}
	else
	{
		for (reg int i = 1; i <= n; ++i)
			if (color[i] == color[1])
				if (rnk[i] > now)
				{
					ans = i;
					now = rnk[i];
				}
	}
	cout << ans << endl;
	return 0;
}