#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, len, now;
int ans1, ans2;
int a[1010];
bool vis[1010];
int dp[1010];

int main()
{
    freopen("missile.in", "r", stdin);
    freopen("missile.out", "w", stdout);

    while (scanf("%d", &a[++n]) != EOF) {} --n;

    dp[1] = 1;
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = i + 1; j <= n; ++j)
            if (a[j] <= a[i])
                dp[j] = max( dp[j], dp[i] + 1 );
    for (reg int i = 1; i <= n; ++i)
        ans1 = max(ans1, dp[i]);
    
    for (reg int i = 1; i <= n; ++i)
    {
        if (vis[i]) continue;
        int last = a[i];
        for (reg int j = 1; j <= n; ++j)
        {
            if (!vis[j] && a[j] <= last)
            {
                vis[j] = true;
                last = a[j];
            }
        }
        ++ans2;
    }
    
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}