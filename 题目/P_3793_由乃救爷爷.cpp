#include <iostream>

#include <cmath>

#define longint long long
#define ull unsigned longint
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

namespace GenHelper
{
    unsigned z1, z2, z3, z4, b;
    unsigned rand_()
    {
        b = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b = ((z2 << 2) ^ z2) >> 27;
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
}
void srand(unsigned x)
{
    using namespace GenHelper;
    z1 = x; z2 = (~x) ^ 0x233333333U; z3 = x ^ 0x1234598766U; z4 = (~x) + 51;
}
int read()
{
    using namespace GenHelper;
    int a = rand_() & 32767;
    int b = rand_() & 32767;
    return a * 32768 + b;
}

struct Block
{
    int L, R, mx;
    int pre[31];
    int suf[31];
    void init()
    {
        pre[L] = a[L]; suf[R] = a[R];
        for (reg int i = L + 1; i <= R; ++i)
            pre[i] = max(a[i], pre[i - 1]);
        for (reg int i = R - 1; i >= L; --i)
            suf[i] = max(a[i], suf[i + 1]);
        mx = pre[R];
    }
} b[900010];

int n, m, s, l, r;
int a[20000010];
int id[20000010];
int st[31][900010];
int blk;
ull ans;

inline void build()
{
    ull cnt = 0;
    
}

inline ull query(int l, int r)
{
    if (l > r) swap(l, r);

}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    srand(s); blk = (int)log2(n);
    for (reg int i = 1; i <= n; ++i)
        a[i] = read(), id[i] = (i - 1) / blk + 1;
    while (m--)
    {
        l = read() % n + 1;
        r = read() % n + 1;
        ans += query(l, r);
    }
    return 0;
}