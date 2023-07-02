// Problem:      P1366 有序表的合并
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1366
// Memory Limit: 128 MB
// Time Limit:   1400 ms
// Created Time: 2023-02-26 20:18:28 

#include <iostream>

// #include <map>
#include <unordered_map>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

u64 n, m, T, l, r, ans;
u64 a[10000010];
u64 b[10000010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (reg int i = 1; i <= n; ++i)
			cin >> a[i];
		for (reg int i = 1; i <= m; ++i)
			cin >> b[i];
		ans = l = r = 0;
		for (reg int i = 1; i <= n; ++i)
		{
			while (b[l] < a[i] && l <= m)
				++l;
			r = l;
			while (b[r] == a[i] && r <= m)
				++r;
			// cout << "[LOG]: l:" << l << " r:" << r << " now:" << a[i] << endl;
			if (a[i] == b[l] && l <= r)
				ans ^= (r - l);
		}
		cout << ans << endl;
		for (reg int i = 1; i <= n; ++i)
			a[i] = 0;
		for (reg int i = 1; i <= m; ++i)
			b[i] = 0;
	}
	return 0;
}