// Problem:      P2704 [NOI2001] 炮兵阵地
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2704
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-01 10:04:14

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

// (si << 1) & last || (si << 2) & last

char ch;
i64 n, m, cnt, ans = -1145141919810;
i64 mp[210];
i64 stt[210];
i64 faq[210];
i64 dp[210][210][210];

inline void init(const i64 &n, const i64 &m)
{
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            cin >> ch, mp[i] = (mp[i] << 1) + (ch == 'P');
    for (reg int i = 0; i < (1 << m); ++i)
        if ( !(((i << 1) & i) || ((i >> 1) & i) || ((i << 2) & i) || ((i >> 2) & i)) )
        {
            ++cnt; stt[cnt] = i;
            for (reg int j = 0; (1 << j) <= i; ++j)
                faq[cnt] += !!(i & (1 << j));        // boat new code method
            if ((i & mp[1]) == i) dp[1][0][cnt] = faq[cnt];
        }
    for (reg int i = 1; i <= cnt; ++i)
        for (reg int j = 1; j <= cnt; ++j)
            if (!(stt[i] & stt[j]) && (mp[2] & stt[j]) == stt[j])
                dp[2][i][j] = dp[1][0][i] + faq[j];
}

int main()
{
    cin >> n >> m;
    if (n == 1 && m == 1) { cout << 1 << endl; return 0; }
    init(n, m);
    for (reg int i = 3; i <= n; ++i)
        for (reg int j = 1; j <= cnt; ++j)
            if ((mp[i] & stt[j]) == stt[j])
                for (reg int k = 1; k <= cnt; ++k)
                    if (!(stt[j] & stt[k]))
                        for (reg int l = 1; l <= cnt; ++l)
                            if (!(stt[k] & stt[l]) && !(stt[j] & stt[l]))
                                dp[i][k][j] = max(dp[i][k][j], dp[i - 1][l][k] + faq[j]);
    for (reg int i = 1; i <= cnt; ++i)
        for (reg int j = 1; j <= cnt; ++j)
            ans = max(ans, dp[n][i][j]);
    cout << ans << endl;
    return 0;
}