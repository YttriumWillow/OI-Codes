// Problem:      P3120 [USACO15FEB]Cow Hopscotch G
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3120
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-02 20:52:52

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 1000000007;

int n, m, k;
int a[1010][1010];
int dp[1010][1010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	
    cin >> n >> m >> k;
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            cin >> a[i][j];
    dp[1][1] = 1;
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            for (reg int x = 1; x < i; ++x)
                for (reg int y = 1; y < j; ++y)
                    dp[i][j] = (dp[i][j] + (a[i][j] != a[x][y]) * dp[x][y]) % mod;
    cout << dp[n][m] << endl;
    return 0;
}