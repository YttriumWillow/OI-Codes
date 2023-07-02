// Problem:      P3263 [JLOI2015]有意义的字符串
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3263
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-05 16:00:10

#include <iostream>

#include <cstring>
#include <cmath>

#define i64 long long
#define i128 __int128
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

template <typename Tp>
inline void read(Tp &x)
{
    x = 0; char ch = getchar(); Tp sgn = 1;
    while (!isdigit(ch)) { if (ch == '-') sgn = -1; ch = getchar(); }
    while (isdigit(ch)) { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    x *= sgn;
}

template <typename Tp>
inline void write(Tp x)
{
    if (x > 9) write(x / 10);
    printf("%c", (int)(x % 10) + '0');
}

const int ord = 2;
const i128 mod = 7528443412579576937;

i128 b, d, n;

struct Matrix
{
    i128 m[ord + 1][ord + 1] = {0};
    void init() { memset(m, 0, sizeof(m)); }
    friend Matrix operator * (const Matrix& A, const Matrix& B)
    {
        Matrix res;
        for (reg int i = 1; i <= ord; ++i)
            for (reg int j = 1; j <= ord; ++j)
                for (reg int k = 1; k <= ord; ++k)
                    res.m[i][j] = (res.m[i][j] % mod + (A.m[i][k] % mod * B.m[k][j] % mod)) % mod;
        return res;
    }
} base, ans;

inline i128 MatrixQuickPow(i128 p)
{
    i128 f = ( (p -= 2) & 1 ) ^ 1;
    while (p > 0)
    {
        if (p & 1)
            ans = ans * base;
        base = base * base;
        p >>= 1;
    }
    return (ans.m[1][1] - f) % mod;
}

inline void init()
{
	base.init();
	ans.init();
    base.m[1][1] = b, base.m[1][2] = 1;
    base.m[2][1] = (d - b * b) / 4, base.m[2][2] = 0;
    ans.m[1][1] = (b * b + d) / 2, ans.m[1][2] = b;
    ans.m[2][1] = 0, ans.m[2][2] = 0;
}

int main()
{
    read(b); read(d); read(n);
    if (n == 0)
        return write(1), 0;
    if (n == 1)
    	return write( ( (i64)( b + sqrt((i64)d) ) / 2 ) % mod ), 0;
    init();
    write(MatrixQuickPow(n));
    return 0;
}