// Problem:	     P1135 奇怪的电梯
// Contest:	     Luogu
// URL:	         https://www.luogu.com.cn/problem/P1135
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-02-25 08:45:32

#include <iostream>

#include <cstring>
#include <ctime>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 inf = 0xffffffffffffff;

i64 n, step, ans = inf;
i64 d[210], a, b;
bool vis[210];
i64 f[210];
time_t st, ed;

void dfs(i64, i64);

int main()
{
    scanf("%lld%lld%lld", &n, &a, &b);
    memset(f, 0x3f, sizeof(f));
    for (reg int i = 1; i <= n; ++i)
        scanf("%lld", &d[i]);
    vis[a] = 1;
    st = clock();
    dfs(a, 0);

    if (ans == inf)
        printf("-1\n");
    else
        printf("%lld\n", ans);

    return 0;
}

void dfs(i64 now, i64 step)
{
    if (now == b)
        ans = min(ans, step);
    if (step > ans)
        return;

    ed = clock();
    if ((ed - st) >= 0.98 * CLOCKS_PER_SEC)
    {
        printf("-1\n");
        exit(0);
    }
    vis[now] = 1;
    if (now - d[now] >= 1)
        if (!vis[now - d[now]])
            dfs(now - d[now], step + 1);
    if (now + d[now] <= n)
        if (!vis[now + d[now]])
            dfs(now + d[now], step + 1);
    vis[now] = 0;
}