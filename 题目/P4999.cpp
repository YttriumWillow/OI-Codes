// Problem:      P4999 烦人的数学作业
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4999
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-13 19:36:04

#include <bits/stdc++.h>

#define i64 long long
#define reg register
#define pb push_back

using namespace std;

const i64 mod = 1000000007;

vector<i64> s;
i64 d[109][2][1700];
i64 l, r, t;

i64 dfs(i64 n, bool bound, i64 sum)
{
    if (n <= 0) return sum;
    if (d[n][bound][sum] != -1)
    	return d[n][bound][sum] %= mod;
    i64 m = bound ? s[n - 1] : 9;
    i64 ans = 0;
    for (reg i64 i = 0; i <= m; ++i)
        ans = (ans % mod + dfs(n - 1, bound && (i == s[n - 1]), (sum + i) % mod) % mod) % mod;
    return d[n][bound][sum] = ans % mod;
}
i64 dp(i64 x)
{
    s.clear(); memset(d, -1, sizeof(d));
    while (x)
        s.pb(x % 10), x /= 10;
    return dfs(s.size(), 1, 0);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        cout << (dp(r) - dp(l - 1) + mod) % mod << '\n';
    }
    return 0;
}