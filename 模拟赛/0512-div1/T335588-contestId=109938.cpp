// Problem:      T335588 搭积木
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T335588?contestId=109938
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-12 14:56:14

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, ans; bool flg;
int a[2000010];
i64 sum;

int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        a[n + i] = a[i];
    }
    int l = 1, r = 0; bool flg = 0;
    while (l < 2 * n && r < 2 * n)
    {
    	flg = 0;
    	while (r - l + 1 < n && r <= 2 * n)
    	{
    		sum += a[++r];
    		cerr << l << ' ' << r << ' ' << sum << endl;
    		if (sum < 0)
    		{
    			l = r + 1, sum = 0;
    			flg = 1; break;
    		}
    	}
    	if (r - l + 1 == n && sum >= 0)
    	{
    		cerr << "~! " << l << ' ' << r << ' ' << sum << endl;
    		++ans;
    	}
    	if (!flg)
    	{
    		sum -= a[l++];
    		if (l == 3) cerr << "Err: " << sum << endl;
    		if (sum < 0)
    		{
    			l = r + 1, sum = 0;
    		}
    	}
    }
    cout << ans << endl;
    return 0;
}