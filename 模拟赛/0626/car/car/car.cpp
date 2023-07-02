// #pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx2,avx512f,popcnt,sse4.1,sse4.2")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e6 + 10;

int n, ans = 1;
char tfc[N], NaN;
bool flg = 1;
int b[N], c[N], s[N];

int main()
{
	// freopen("car.in", "r", stdin);
	// freopen("car.out", "w", stdout);
	
	scanf("%d", &n); getchar();
	for (int i = 1; i <= n; ++i)
	{
		tfc[i] = getchar();
		b[i] = b[i - 1] + (tfc[i] == 'B');
		c[i] = c[i - 1] + (tfc[i] == 'C');
		s[i] = s[i - 1] + (tfc[i] == 'S');
	}
	
	// special
	for (int i = 2; i <= n; ++i)
		if (tfc[i] != tfc[i - 1])	
			flg = false;
	if (flg) { cout << n << endl, exit(0); }
	// -------
	
	// if (n > 10000) { cheat(); exit(0); }
	
	for (int i = 1; i <= n; ++i)
	{
		int j = i + ans + 2;
		for (; j + 4 <= n; j += 4)
		{
			int cb0 = b[j] - b[i - 1];
			int cc0 = c[j] - c[i - 1];
			int cs0 = s[j] - s[i - 1];
			if (!(cb0 == cc0 || cc0 == cs0 || cb0 == cs0))
				ans = max(ans, j - i + 1);
			
			int cb1 = b[j + 1] - b[i - 1];
			int cc1 = c[j + 1] - c[i - 1];
			int cs1 = s[j + 1] - s[i - 1];
			if (!(cb1 == cc1 || cc1 == cs1 || cb1 == cs1))
				ans = max(ans, j - i + 2);
				
			int cb2 = b[j + 2] - b[i - 1];
			int cc2 = c[j + 2] - c[i - 1];
			int cs2 = s[j + 2] - s[i - 1];
			if (!(cb2 == cc2 || cc2 == cs2 || cb2 == cs2))
				ans = max(ans, j - i + 3);
				
			int cb3 = b[j + 3] - b[i - 1];
			int cc3 = c[j + 3] - c[i - 1];
			int cs3 = s[j + 3] - s[i - 1];
			if (!(cb3 == cc3 || cc3 == cs3 || cb3 == cs3))
				ans = max(ans, j - i + 4);
		}
		for (; j <= n; ++j)
		{
			int cb = b[j] - b[i - 1];
			int cc = c[j] - c[i - 1];
			int cs = s[j] - s[i - 1];
			if (!(cb == cc || cc == cs || cb == cs))
				ans = max(ans, j - i + 1);
		}
	}
	cout << ans << endl;
	return 0;
}