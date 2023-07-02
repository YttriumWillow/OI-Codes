// Problem:      P4168 [Violet]蒲公英
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4168
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-17 21:10:41 

#include <iostream>

#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, len;
int l, r, res;
int a[40010];
int b[40010];
int buc[100000010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	len = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; ++i)
		a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;
	while (m--)
	{
		cin >> l >> r;
		l = (l + res - 1) % n + 1;
		r = (r + res - 1) % n + 1;
		if (l > r) swap(l, r);
		for (int i = 1; i <= len; ++i)
			buc[i] = 0;
		int mx = 0;
		for (int i = l; i <= r; ++i)
			++buc[a[i]];
		for (int i = 1; i <= len; ++i)
			if (buc[i] > mx) mx = buc[i], res = b[i];
		cout << res << endl;
	}
	return 0;
}