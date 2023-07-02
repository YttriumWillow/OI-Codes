// Problem:      P2789 直线交点数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2789
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-01 15:35:12 

#include <iostream>
#include <set>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back
#define Point pair<double, double>
#define kk first
#define bb second

using namespace std;

int n, ans;
double k[31];
double b[31];
double xk, xb, k1, k2, b1, b2;

set<Point> pos;

inline void init()
{
    for (reg int i = 1; i <= n; ++i)
    {
        k[i] = i;
        b[i] = 2 * i + rand() % 114;
    }
}

int main()
{
	srand((int)('f' + 'a' + 'q'));
	
    scanf("%d", &n);
    init(); Point p;
    for (reg int i = 1; i <= n; ++i)
    {
        for (reg int j = 1; j < i; ++j)
        {
            k1 = k[i]; b1 = b[i];
            k2 = k[j]; b2 = b[j];
            p = { (b2 - b1) / (k1 - k2), k1 * (b2 - b1) / (k1 - k2) + b1 };
            pos.insert(p);
        }
    }
    for (auto x : pos)
    	cerr << x.first << ' ' << x.second << endl;
    printf("%lld\n", pos.size());
    return 0;
}