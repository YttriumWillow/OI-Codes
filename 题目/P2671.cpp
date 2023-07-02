// Problem:      P2671 [NOIP2015 普及组] 求和
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2671
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-14 20:55:57 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

const int xhg = 10007;

using namespace std;

i64 n, m, ans;
i64 a[100010];
i64 color[100010];

void upd(i64 i, i64 j, i64 x, i64 y) { ans = (ans % xhg + ((i % xhg + j % xhg) % xhg) * ((x % xhg + y % xhg) % xhg)) % xhg; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i];
	for (reg int i = 1; i <= n; ++i)
		cin >> color[i];
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = i + 1; j <= n; ++j)
			if (color[i] == color[j] && (i + j) % 2 == 0)
				upd(i, j, a[i], a[j]);
	cout << ans << endl;
	return 0;
}