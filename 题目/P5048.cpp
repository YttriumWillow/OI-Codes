// Problem:      P5048 [Ynoi2019 模拟赛] Yuno loves sqrt technology III
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5048
// Memory Limit: 62 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-18 21:35:34 

#include <iostream>

#include <algorithm>
#include <cmath>
#include <vector>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

#include <cstring>
namespace bufIO
{
    const int _Pu = 1 << 16;
    const int _d = 32;
    char buf[_Pu], obuf[_Pu];
    char *inl = buf + _Pu, *inr = buf + _Pu;
    char *outl = obuf, *outr = obuf + _Pu - _d;
    inline void flushin()
    {
        memmove(buf, inl, inr - inl);
        int rlen = fread(buf + (inr - inl), 1, inl - buf, stdin);
        if (inl - rlen > buf) { buf[inr - inl + rlen] = EOF; }
        inl = buf;
    }
    inline void flushout() { fwrite(obuf, outl - obuf, 1, stdout), outl = obuf; }
    template <typename _Tp>
    inline void read(_Tp &x)
    {
        if (inl + _d > inr) { flushin(); }
        int isne = 0;
        for (; !isdigit(*inl); ++inl) { isne = (*inl == '-'); }
        x = (*inl++ - '0');
        for (; isdigit(*inl); ++inl) { x = x * 10 + (*inl - '0'); }
        if (isne) { x = -x; }
    }
    template <typename _Tp>
    inline void writeln(_Tp x, char end = '\n')
    {
        if (outl > outr) { flushout(); }
        if (x < 0) { *outl++ = '-'; x = -x; }
        char sta[20]; char *top = sta;
        do { *top++ = (x % 10) + '0'; x /= 10; } while (x);
        do { *outl++ = *--top; } while (top != sta);
        (*outl++) = end;
    }
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
}
using namespace bufIO;

const int N = 500010;
const int BLK = 810;

int n, m, len;
int l, r, x;
int a[N], b[N];

int tot, blk, lmt;
int buc[BLK], pos[N], f[BLK][BLK];
int lft[BLK], rgt[BLK], bel[N];

vector<int> vec[N];

inline void build(int n)
{
    blk = ceil(pow(n, 0.48));
    // blk = (int)sqrt(n);
    tot = (n - 1) / blk + 1;
    // tot = n / blk + !!(n % blk);
    
    sort(b + 1, b + n + 1);
    len = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;
    for (int i = 1; i <= n; ++i)
    {
        vec[a[i]].pb(i);
        pos[i] = vec[a[i]].size() - 1;
    }
    
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
    int L = bel[l], R = bel[r], res = 0;
    if (L == R)
    {
    	for (int i = l; i <= r; ++i)
    		buc[a[i]] = 0; 
        for (int i = l; i <= r; ++i)
            res = max(res, ++buc[a[i]]);
        return res;
    }
    res = f[L + 1][R - 1];
    for (int i = l; i <= rgt[L]; ++i)
        while (pos[i] + res < (int)vec[a[i]].size()
        	&& vec[a[i]][pos[i] + res] <= r)
            ++res;
    for (int i = lft[R]; i <= r; ++i)
        while (pos[i] - res >= 0 && vec[a[i]][pos[i] - res] >= l)
            ++res;
    return res;
}

int main()
{
    read(n, m);
    for (int i = 1; i <= n; ++i)
        read(a[i]), b[i] = a[i];

    build(n);

    while (m--)
    {
        read(l, r);
        l ^= x; r ^= x;
        if (l > r) l ^= r ^= l ^= r;
        writeln(x = query(l, r));
    }
    flushout();
    return 0;
}