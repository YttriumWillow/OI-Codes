#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx512f,sse4.1,sse4.2")

#include <iostream>

#define i64 long long
#define reg register
#define endl '\n'
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

const int N = 760;
const int mod = 1e9 + 7;
int n, m, k;
int a[N][N];
int dp[N][N];
i64 sum[N][N];
i64 col[N * N];

int main()
{
	read(n, m, k);
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = 1; j <= m; ++j)
			read(a[i][j]);
	dp[1][1] = sum[1][1] = 1;
	for (reg int i = 2; i <= n; ++i)
		sum[i][1] = sum[i - 1][1] + dp[i][1];
	for (reg int j = 2; j <= m; ++j)
		sum[1][j] = sum[1][j - 1] + dp[1][j];
	for (reg int i = 2; i <= n; ++i)
	{
		for (reg int j = 2; j <= m; ++j)
		{
			for (reg int k = 1; k < i; ++k)
				col[a[k][j - 1]] += dp[k][j - 1], col[a[k][j - 1]] %= mod;
			dp[i][j] = ((sum[i - 1][j - 1] - col[a[i][j]]) % mod + mod) % mod;
			sum[i][j] = ((sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + dp[i][j]) % mod + mod) % mod;
		};
		for (reg int l = 0; l <= k; ++l)
			col[l] = 0;
	}
	writeln(dp[n][m]); flushout();
	return 0;
}