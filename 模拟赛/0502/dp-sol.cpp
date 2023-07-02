#pragma GCC target("avx","sse2","sse3","sse4","mmx","avx512f","sse4.1","sse4.2")

#include <iostream>

#define i64 long long
#define reg register
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

const int N = 755;
const int mod = 1e9 + 7;

int n, m, k;
int a[N][N];
int dp[N][N];
int rt[N * N];

struct Node { int ls, rs, sum; };
Node t[N * N * 12]; int cnt = 0;
inline void pushup(int p) { t[p].sum = (t[t[p].ls].sum + t[t[p].rs].sum) % mod; }
inline void modify(int &p, int l, int r, int x, int y)
{
	if (!p) p = ++cnt;
	if (l == r) { t[p].sum = (t[p].sum + y) % mod; return; }
	reg int mid = (l + r) >> 1;
	if (x <= mid) modify(t[p].ls, l, mid, x, y);
	if (mid <  x) modify(t[p].rs, mid + 1, r, x, y);
	pushup(p);
}
inline i64 query(int p, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr)
	{ return t[p].sum; }
	reg int mid = (l + r) >> 1; reg i64 res = 0;
	if (t[p].ls && ql <= mid) res += query(t[p].ls, l, mid, ql, qr);
	if (t[p].rs && mid <  qr) res += query(t[p].rs, mid + 1, r, ql, qr);
	return res % mod;
}

int main()
{
	read(n, m, k);
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = 1; j <= m; ++j)
			read(a[i][j]);
	dp[1][1] = 1;
	modify(rt[0], 1, m, 1, 1);
	modify(rt[a[1][1]], 1, m, 1, dp[1][1]);
	for (reg int i = 2; i <= n; ++i)
	{
		for (reg int j = 1; j <= m; ++j)
			dp[i][j] = ((query(rt[0], 1, m, 1, j - 1) - 
						 query(rt[a[i][j]], 1, m, 1, j - 1))
						 % mod + mod) % mod;
		for (reg int j = 1; j <= m; ++j)
		{
			modify(rt[a[i][j]], 1, m, j, dp[i][j]);
			modify(rt[0], 1, m, j, dp[i][j]);
		}
	}
	writeln(dp[n][m]); flushout();
	return 0;
}