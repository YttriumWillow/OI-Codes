// Problem:      P3200 [HNOI2009]有趣的数列
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3200
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-09 20:13:49

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, p, ans = 1;
int cnt[2000010];
int prime[2000010];
int mpd[2000010];

inline int fpow(int a, int k)
{
    int res = 1;
    for (; k; k >>= 1)
    {
        if (k & 1) res = 1ll * res * a % p;
        a = 1ll * a * a % p;
    }
    return res;
}

inline void init(int lmt)
{
    for (reg int i = 2; i <= lmt; ++i)
    {
        if (!prime[i]) prime[++prime[0]] = i, mpd[i] = i;
        for (reg int j = 1; j <= prime[0] && i * prime[j] <= lmt; ++j)
        {
            prime[i * prime[j]] = 1;
            mpd[i * prime[j]] = prime[j];
            if (!(i % prime[j])) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;
    init(2 * n);
    for (reg int i = 1; i <= n; ++i)
        cnt[i] = -1;
    for (reg int i = n + 2; i <= 2 * n; ++i)
        cnt[i] = 1;
    for (reg int i = n * 2; i > 1; --i)
    {
        if (mpd[i] < i)
        {
            cnt[mpd[i]] += cnt[i];
            cnt[i / mpd[i]] += cnt[i];
        }
    }
    for (reg int i = 2; i <= n * 2; ++i)
        if (mpd[i] == i)
            ans = 1ll * ans * fpow(i, cnt[i]) % p;
    cout << ans << endl;
    return 0;
}