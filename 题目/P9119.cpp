// Problem:      P9119 [春季测试 2023] 圣诞树【民间数据，spj 暂缺】
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9119?contestId=102679
// Memory Limit: 1 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-07 18:57:28

#include <iostream>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const double inf = 1e18;

namespace Solution
{
int n;
double now;
double dp[20][1 << 20];
double pre[20][1 << 20];
double dis[21][21];
struct Node { double x, y; } a[1010];
inline double getDis(Node A, Node B) { return hypot(A.x - B.x, A.y - B.y); }
inline void init()
{
    a[0] = {0, 0};
    int st = 1;
    for (int i = 1; i <= n; ++i) // f**king initalize
        if (a[i].y > a[st].y)
            st = i;
    dp[st][1 << st] = 0;
    pre[st][1 << st] = -1;
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 0; j <= (1 << n); ++j)
            dp[i][j] = inf;
    for (reg int i = 0; i <= n; ++i)
        for (reg int j = i + 1; j <= n; ++j)
            dis[i][j] = dis[j][i] = getDis(a[i], a[j]);
    for (reg int i = 1; i <= n; ++i)
        dp[i][1 << (i - 1)] = dis[st][i]; // this line is a s**t
                                          // faq i debug one night
}
inline void Subtask1()
{
    for (reg int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y;
    init();

    for (reg int k = 1; k <= (1 << n); ++k)
        for (reg int i = 1; i <= n; ++i)
        {
            if (!(k & (1 << (i - 1))))
                continue;
            for (reg int j = 1; j <= n; ++j)
            {
                if (i == j || !(k & (1 << (i - 1))))
                    continue;
                now = dp[j][k - (1 << (i - 1))] + dis[i][j];
                if (dp[i][k] > now)
                    dp[i][k] = now, pre[i][k] = j;
            }
        }

    // find your mom's path
    // FAQ
    int pos = 1, d;
    vector<int> path;
    for (reg int i = 1; i <= n; ++i)
        if (dp[i][(1 << n) - 1] < dp[pos][(1 << n) - 1])
            pos = i;
    for (reg int S = (1 << n) - 1; S >= 0; S -= d)
    {
        path.push_back(pos);
        d = 1 << (pos - 1);
        pos = pre[pos][S];
    }
    path.pop_back();
    reverse(path.begin(), path.end());
    for (auto x : path)
        cout << x << ' ';

    return;
}
inline void Subtask2()
{
    cout << "FAQ" << endl;
}
void Solve()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    if (n <= 20)
        Subtask1();
    // else
        // Subtask2();
}
// a s**t
} // namespace Solution

int main()
{
    Solution::Solve();
    return 0;
}