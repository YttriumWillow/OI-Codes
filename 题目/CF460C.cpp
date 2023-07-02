// Problem:      Present
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF460C
// Memory Limit: 250 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-11 19:47:49

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, w;
int a[100010];
int dif[100010];

inline bool check(int x)
{
    reg int now = 0, usd = 0;
    for (reg int i = 1; i <= n; ++i)
        dif[i] = a[i] - a[i - 1];
    for (reg int i = 1; i <= n; ++i)
    {
        now += dif[i];
        if (now < x)
		{
        	usd += x - now;
        	dif[ min(i + w, n + 1) ] -= x - now;
        	now = x;
        }
        if (usd > m) return 0;
    }
    return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin >> n >> m >> w;
    for (reg int i = 1; i <= n; ++i)
        cin >> a[i];
    // reg int l = 1, r = 1e9; // before
    reg int l = 1, r = 1e9 + 114514;
    while (r - l > 1)
    {
        reg int mid = (l + r) >> 1;
    	check(mid) ? l = mid : r = mid;
    }
    cout << l << endl;
    return 0;
}