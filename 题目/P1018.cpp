#include <iostream>

#define i64 long long
#define i128 __int128
#define u128 unsigned i128
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 40 + 50;

int n, m;
u128 a[N];
u128 dp[N][N];

template<typename Tp>
inline void read(Tp& x)
{
    x = 0; char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch ^ 48);
        ch = getchar();
    }
}
template<typename Tp>
inline void print(Tp x)
{
    if (x > 9) print(x / 10);
    putchar(x % 10 + 48);
}
inline u128 num(u128 x, u128 y)
{
    reg u128 ans = 0;
    for (reg u128 i = x; i <= y; ++i)
        ans = ans * 10 + a[i];
    return ans;
}
signed main()
{
	read(n); read(m); // getchar();
    for (reg int i = 1; i <= n; ++i)
        a[i] = getchar() - '0';
    for (reg int i = 1; i <= n; ++i)
        dp[i][0] = num(1, i);
    for (reg int i = 2; i <= n; ++i)
        for (reg int j = 1; j <= m && j < i; ++j)
            for (reg int l = j; l < i; ++l)
                dp[i][j] = max(dp[i][j], dp[l][j - 1] * num(l + 1, i));
    print(dp[n][m]);
    for (reg int i = 1; i <= n; ++i)
    {
        for (reg int j = 1; j <= m; ++j)
            print(dp[i][j]), putchar(' ');
        putchar('\n');
    }
    return 0;
}