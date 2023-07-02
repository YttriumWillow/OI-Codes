// Problem:	P3392 涂国旗
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P3392
// Memory Limit:	125 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-24 15:50:55

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, res, ans = 0x7fffffff;
char color;

struct Line
{
    int w = 0, b = 0, r = 0;
} l[51];

int main()
{
    cin >> n >> m;
    for (reg int i = 1; i <= n; ++i)
    {
    	// getchar();
        for (reg int j = 1; j <= m; ++j)
        {
            cin >> color;
            // cout << color << ' ';
            if (color == 'W') ++l[i].w;
            if (color == 'B') ++l[i].b;
            if (color == 'R') ++l[i].r;
        }
        // printf("w:%d b:%d r:%d\n", l[i].w, l[i].b, l[i].r);
        // getchar();
    }
    for (reg int i = 2; i < n; ++i)
        for (reg int j = i + 1; j <= n; ++j)
        {
            res = 0;
            for (reg int x = 1; x < i; ++x)
                res += m - l[x].w;
            for (reg int x = i; x < j; ++x)
                res += m - l[x].b;
            for (reg int x = j; x <= n; ++x)
                res += m - l[x].r;
            ans = min(ans, res);
        }
    cout << ans << endl;
    return 0;
}