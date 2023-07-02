// Problem:      P1991 无线通讯网
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1991
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-26 21:16:40

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 maxn = 501;
const i64 maxm = 250001;

i64 fa[maxn];

struct Node
{
    i64 u, v;
    double w;
    bool operator < (Node qaq) { return w < qaq.w; }
} e[maxm];

struct point { i64 x, y; } p[maxn];

inline i64 find(i64 x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

bitset<maxn> vis;
i64 n, m, s, cnt;

int main()
{
    scanf("%lld%lld", &s, &n);
    for (reg int i = 1; i <= n; ++i)
        scanf("%lld%lld", &p[i].x, &p[i].y), fa[i] = i;
    for (reg int i = 1; i <= n; ++i)
    {
        for (reg int j = i + 1; j <= n; ++j)
        {
        	++m;
            e[m].u = i;
            e[m].v = j;
            e[m].w = 
			(double)sqrt( (1.0 * p[i].x - p[j].x) * (p[i].x - p[j].x)
					    + (1.0 * p[i].y - p[j].y) * (p[i].y - p[j].y) );
        }
    }
    sort(e + 1, e + m + 1);
    for (reg int i = 1; i <= m; ++i)
    {
    	int x = find(e[i].u);
    	int y = find(e[i].v);
        if (x == y) { continue; }
        fa[x] = y; ++cnt;
        if (cnt == n - s) { printf("%.2lf\n", e[i].w); return 0; }
    }
    return 0;
}