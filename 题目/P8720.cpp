// Problem:      P8720 [蓝桥杯 2020 省 B2] 平面切分
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8720
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-02-25 14:11:16

#include <iostream>

#include <set>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back
#define Line pair<double, double>
#define kk first
#define bb second

using namespace std;

int n, tmp, ans = 1;
double xk, xb;
double k1, k2, b1, b2;
set<Line> l;
vector<int> k, b;

void init()
{
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%lf%lf", &xk, &xb);
        l.insert(make_pair(xk, xb));
    }
    for (reg auto x : l)
        k.pb(x.kk), b.pb(x.bb);
}

int main()
{
    scanf("%d", &n);
    init();
    
    Line p;
    for (reg int i = 0; i < (int)k.size(); ++i)
    {
        set<Line> pos;
        for (reg int j = i - 1; j >= 0; --j)
        {
            k1 = k[i], b1 = b[i],
            k2 = k[j], b2 = b[j];
            if (k1 == k2) continue;		// 平行
            p.kk = (b2 - b1) / (k1 - k2); // 求交点
            p.bb = k1 * ((b2 - b1) / (k1 - k2)) + b1;
            pos.insert(p);
        }
        ans += pos.size() + 1; // 交点加入
    }
    printf("%d\n", ans);
    return 0;
}