// Problem:      Subtract Operation
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF1656B
// Memory Limit: 250 MB
// Time Limit:   1000 ms
// Created Time: 2023-02-28 21:01:02

#include <iostream>

#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int T, n, k;
int a[200010];

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k); k = abs(k);
        for (reg int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1); a[n + 1] = 0x6fffffff;
        int l = 1, r = 1;
        while (a[r] - a[l] != k && l <= n && r <= n)
        {
        	if (a[r] - a[l] > k && l <= n)
        		++l;
        	if (a[r] - a[l] < k && r <= n)
        		++r;
        	if (a[r] - a[l] == k)
        		break;
        }
        if (a[r] - a[l] == k)
        	printf("YES\n");
        else
        	printf("NO\n");
    }
    return 0;
}