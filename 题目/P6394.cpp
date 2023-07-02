// Problem:      P6394 樱花，还有你
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6394
// Memory Limit: 64 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-27 19:17:00 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

const int mod = 10086001;

i64 n, m;
i64 a[5010];
i64 f[5010][5010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n; f[0][0] = 1;
    for (reg int i = 1; i <= n; ++i)
        cin >> a[i];
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 0; j <= m; ++j)
            for (reg int k = 0; k <= min((i64)j, a[i]); ++k)
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
    cout << f[n][m] << endl;
    return 0;
}