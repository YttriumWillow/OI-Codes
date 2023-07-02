// Problem:	P1163 银行贷款
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P1163
// Memory Limit:	125 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-25 08:28:06

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const double eps = 1e-7;

double n, m, k;
double ans;

bool check(double now)
{
    double res = n;
    for (reg int i = 1; i <= k; ++i)
    {
        res = res * (1 + now) - m;
        if (res < 0)
            return false;
    }
    return res >= 0;
}

int main()
{
    scanf("%lf%lf%lf", &n, &m, &k);

    double l = 0, r = 10.0;
    while (r - l >= eps)
    {
        double mid = (l + r) / 2.0;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    // cout << l << endl;
    printf("%.1lf", l * 100);
    return 0;
}