// Problem:      P1896 [SCOI2005] 互不侵犯
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1896
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-09 19:37:00

#include <iostream>

#include <bitset>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 dp[11][91][2001];
i64 kingnum[2001];
i64 state[2001];
i64 n, k, cnt, ans;

bitset<11> b;

inline void init()
{
    for (reg i64 s = 0; s < (1 << n); ++s)
    {
        b = s;
        kingnum[s] = b.count();
        if ( !( ( (s << 1) | (s >> 1) ) & s) )
            state[++cnt] = s;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k; init(); dp[0][0][0] = 1;
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= cnt; ++j)
        {
            for (reg int x = 1, now = state[j]; x <= cnt; ++x)
            {
                int last = state[x];
                if ( !( (last | (last << 1) | (last >> 1) ) & now) )
                    for (reg int y = 0; y <= k; ++y)
                        if (y - kingnum[now] >= 0)
                            dp[i][y][now] += dp[i - 1][y - kingnum[now]][last];
            }
        }
    for (reg int i = 1; i <= cnt; ++i)
        ans += dp[n][k][state[i]];
    cout << ans << endl;
    return 0;
}