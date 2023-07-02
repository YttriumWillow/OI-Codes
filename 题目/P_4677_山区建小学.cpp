#include <iostream>

#include <cmath>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int inf = 0x3fffffff;

int n, m;
int a[50010];
int dis[510][510];
int dp[510][510];

int main()
{
    scanf("%d%d", &n, &m);
    for (reg int i = 2; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (reg int l = 1; l <= n; ++l)
        for (reg int r = 1; r <= n; ++r)
        {
            int mid = (l + r) >> 1;
            for (reg int k = l; k <= r; ++k)
                dis[l][r] += abs(a[mid] - a[k]);
        }
    for (reg int i = 0; i <= n; ++i)
        for (reg int j = 0; j <= m; ++j)
            dp[i][j] = inf;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (j > i)
            {
                dp[i][j] = 0;
                continue;
            }
            for (int k = j - 1; k <= i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + dis[k + 1][i]);
        }
    printf("%d\n", dp[n][m]);
    return 0;
}