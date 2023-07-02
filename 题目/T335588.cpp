// Problem:      T335588 搭积木
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T335588
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-13 15:39:32 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 inf = 0x7fffffffffffffff;

int	n, ans;
int a[1000010];
i64 sum[1000010];
i64 pre[1000010];
i64 suf[1000010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		pre[i] = min(pre[i - 1], sum[i]);
	}
	suf[n + 1] = inf;
	for (reg int i = n; i >= 1; --i)
		suf[i] = min(suf[i + 1], sum[i]);
	for (reg int k = 1; k <= n; ++k)
		if ( (suf[k] - sum[k - 1] >= 0)
		  && (pre[k - 1] + sum[n] - sum[k - 1] >= 0) )
			++ans;
	cout << ans << endl;
	return 0;
}