// Problem:      P2717 寒假作业
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2717
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-02 10:20:05 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n; i64 k, ans;
int a[200010];
i64 sum[200010];

inline void CDQ(int l, int r)
{
	if (l == r) return;
	int mid = (l + r) >> 1;
	CDQ(l, mid); CDQ(mid + 1, r);
	int i = l;
	for (reg int j = mid + 1; j <= r; ++j)
	{
		while (i <= mid && sum[i] <= sum[j]) ++i;
		ans += (i - l);
	}
	sort(sum + l, sum + r + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i], sum[i] = sum[i - 1] + a[i] - k;
	CDQ(0, n);
	cout << ans << endl;
	return 0;
}