// Problem:      P3590 [POI2015] TRZ
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3590
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-27 16:34:21 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e6 + 10;

int n, ans = 1;
char t[N]; bool flg = 1;
int b[N], c[N], s[N];

int main()
{
	cin >> n; getchar();
	for (int i = 1; i <= n; ++i)
	{
		t[i] = getchar();
		b[i] = b[i - 1] + (t[i] == 'B');
		c[i] = c[i - 1] + (t[i] == 'C');
		s[i] = s[i - 1] + (t[i] == 'S');
	}
	
	for (int i = 1; i <= 3; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			int cb = b[j] - b[i - 1];
			int cc = c[j] - c[i - 1];
			int cs = s[j] - s[i - 1];
			if (cb != cc && cc != cs && cs != cb)
				ans = max(ans, j - i + 1);
		}
	for (int j = n - 2; j <= n; ++j)
		for (int i = 1; i <= j - 1; ++i)
		{
			int cb = b[j] - b[i - 1];
			int cc = c[j] - c[i - 1];
			int cs = s[j] - s[i - 1];
			if (cb != cc && cc != cs && cs != cb)
				ans = max(ans, j - i + 1);
		}
	cout << ans << endl;
	return 0;
}