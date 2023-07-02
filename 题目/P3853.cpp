// Problem:	P3853 [TJOI2007]路标设置
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P3853
// Memory Limit:	128 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-24 16:12:20

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int l, n, k, ans;

int a[100010];

bool check(int now)
{
    int res = 0, last = 0;
    for (reg int i = 2; i <= n; ++i)
        if (a[i] - last > now)
        {
        	++res;
        	last += now;
        	if (!(res <= k)) return false;
        	--i;
        }
        else
        	last = a[i];
    return res <= k;
}

int main()
{
    scanf("%d%d%d", &l, &n, &k);

    for (reg int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    int l = 0, r = 10e7 + 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        // cout << mid << endl;
        if (check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}