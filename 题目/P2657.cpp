// Problem:      P2657 [SCOI2009] windy 数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2657
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-12 21:01:22

#include <iostream>

#include <cstring>
#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 l, r, cnt;
i64 dp[11][11];
int a[33];

i64 dfs(int now, int pre, bool f1, bool lmt)
{
    if (now > cnt) return 1;
    if (!lmt && dp[now][pre] != -1)
        return dp[now][pre];

    int m = lmt ? a[cnt - now + 1] : 9;
    i64 ans = 0;
    for (reg int i = 0; i <= m; ++i)
    {
        if (abs(i - pre) < 2)
            continue;
        if (f1 && (i == 0))
            ans += dfs(now + 1, -2, 1, lmt && (i == m));
        else
            ans += dfs(now + 1, i, 0, lmt && (i == m));
    }
    if (!lmt && !f1) dp[now][pre] = ans;
    return ans;
}

i64 solve(i64 n)
{
    cnt = 0;
    memset(dp, -1, sizeof dp);
    while (n)
        a[++cnt] = n % 10, n /= 10;
    return dfs(1, -2, 1, 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << endl;
    return 0;
}