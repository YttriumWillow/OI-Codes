#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint n, m, xx, yy;
longint dp[31][31];

bool check(longint x, longint y)
{
	if (x == xx && y == yy)			return false;
	if (x == xx - 2 && y == yy - 1) return false;
	if (x == xx - 2 && y == yy + 1) return false;
	if (x == xx - 1 && y == yy - 2) return false;
	if (x == xx - 1 && y == yy + 2) return false;
	if (x == xx + 1 && y == yy - 2) return false;
	if (x == xx + 1 && y == yy + 2) return false;
	if (x == xx + 2 && y == yy - 1) return false;
	if (x == xx + 2 && y == yy + 1) return false;
	return true;
}

int main()
{
	cin >> n >> m >> xx >> yy;
//	for (reg longint i = 0; i <= n; ++i)
//		dp[i][0] = 1;
//	for (reg longint j = 0; j <= m; ++j)
//		dp[0][j] = 1;
	for (reg longint i = 0; i <= n; ++i)
		for (reg longint j = 0; j <= m; ++j)
		{
			if (i == 0 && j == 0)
				dp[i][j] = 1;
			else if (i == 0)
				dp[i][j] = dp[i][j - 1];
			else if (j == 0)
				dp[i][j] = dp[i - 1][j];
			else 
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			
			if (!check(i, j))
			{
				dp[i][j] = 0;
			} 
		}
	cout << dp[n][m] << endl;
	return 0;
}
