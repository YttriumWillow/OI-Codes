// Problem:      P4168 [Violet]蒲公英
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4168
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-18 18:50:00

#include <iostream>

#include <algorithm>
#include <cmath>
#include <vector>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 40010;
const int BLK = 210;

int n, m, len;
int l, r, x;
int a[N], b[N];

int tot, blk, lmt;
int ax[N], f[BLK][BLK];
int buc[BLK], cnt[BLK], md[BLK];
int lft[BLK], rgt[BLK], bel[N];

vector<int> vec[N];

inline void build(int n)
{
    blk = (int)sqrt(n);
    tot = n / blk + !!(n % blk);
    for (int i = 1; i <= tot; ++i)
    {
        lft[i] = rgt[i - 1] + 1;
        rgt[i] = i * blk;
    }
    rgt[tot] = n;
    for (int i = 1; i <= tot; ++i)
    {
        fill(buc + 1, buc + len + 1, 0);
        for (int j = lft[i]; j <= rgt[i]; ++j)
            bel[j] = i;
        for (int j = i; j <= tot; ++j)
        {
            f[i][j] = f[i][j - 1];
            for (int k = lft[j]; k <= rgt[j]; ++k)
                f[i][j] = max(f[i][j], ++buc[a[k]]);
        }
    }
}

inline int query(int l, int r)
{
    int L = bel[l], R = bel[r];
    fill(buc + 1, buc + len + 1, 0);
    int res = 0;
    if (L == R)
    {
        for (int i = l; i <= r; ++i)
            res = max(res, ++buc[a[i]]);
        return res;
    }

    res = f[L + 1][R - 1];
    for (int i = l; i <= rgt[L]; ++i)
    {
        int p = ax[i];
        int v = p + res;
        while (v < vec[a[i]].size() && vec[a[i]][v] <= r)
            ++res, ++v;
    }
    for (int i = lft[R]; i <= r; ++i)
    {
        int p = ax[i];
        int v = p - res;
        while (v >= 0 && vec[a[i]][v] >= l)
            ++res, --v;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], b[i] = a[i];

    sort(b + 1, b + n + 1);
    len = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;

    for (int i = 1; i <= n; ++i)
    {
        vec[a[i]].emplace_back(i);
        ax[i] = vec[a[i]].size() - 1;
    }

    build(n); fill(buc + 1, buc + len + 1, 0);

    while (m--)
    {
        cin >> l >> r;
        l ^= x
        r ^= x;
        if (l > r) l ^= r ^= l ^= r;
        x = query(l, r);
        cout << x << endl;
    }
    return 0;
}