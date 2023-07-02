// Problem:      P1433 吃奶酪
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1433
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-05 21:07:46

#include <iostream>

#include <cfloat>
#include <cmath>
#include <iomanip>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const double inf = DBL_MAX;

struct Node { double x, y; } a[16];

int n;
double ans = inf;
double dp[16][33000];
double dis[16][16];

inline double getDis(Node& A, Node& B) { return hypot(A.x - B.x, A.y - B.y); };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	// auto getDis = [](Node A, Node B) { return hypot(A.x - B.x, A.y - B.y); };
	
    cin >> n;
    for (reg int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;

    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 0; j <= (1 << n); ++j)
            dp[i][j] = inf;
    a[0] = {0, 0};
    for (reg int i = 0; i <= n; ++i)
        for (reg int j = i + 1; j <= n; ++j)
            dis[i][j] = dis[j][i] = getDis(a[i], a[j]);
    for (reg int i = 1; i <= n; ++i)
        dp[i][1 << (i - 1)] = dis[0][i];
    for (reg int k = 1; k <= (1 << n); ++k)
        for (reg int i = 1; i <= n; ++i)
        {
            if (!(k & (1 << (i - 1)))) continue;
            for (reg int j = 1; j <= n; ++j)
            {
                if (i == j || !(k & (1 << (i - 1)))) continue;
                dp[i][k] = min(dp[i][k], dp[j][k - (1 << (i - 1))] + dis[i][j]);
            }
        }
    for (reg int i = 1; i <= n; ++i)
        ans = min(ans, dp[i][(1 << n) - 1]);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}