// Problem:      P5459 [BJOI2016]回转寿司
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5459
// Memory Limit: 250 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-02 10:17:20 

// Problem:      Petya and Array
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF1042D
// Memory Limit: 250 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-02 09:35:53 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, L, R; i64 ans;
int a[100010];
i64 sum[100010];

inline void CDQ(int l, int r)
{
	if (l == r) return;
	int mid = (l + r) >> 1;
	CDQ(l, mid); CDQ(mid + 1, r);
	int pl = l, pr = l - 1;
	for (reg int i = mid + 1; i <= r; ++i)
	{
		while (pr < mid && sum[i] >= sum[pr + 1] + L) ++pr;
		while (pl <= mid && sum[i] > sum[pl] + R) ++pl;
		ans += pr - pl + 1;
	}
	sort(sum + l, sum + r + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> L >> R;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i], sum[i] = sum[i - 1] + a[i];
	CDQ(0, n);
	cout << ans << endl;
	return 0;
}