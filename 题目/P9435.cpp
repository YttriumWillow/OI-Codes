// Problem:      P9435 『XYGOI round1』三个数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9435
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-02 06:52:17 

#include <iostream>

#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 LMT = 1e12;
const int N  = 114514;

i64 T, n, q;
i64 f[N] = { 0, 0, 1, 2, 3 };
i64 sum[N];

inline void init()
{
	for (int i = 5; f[i - 1] <= LMT; ++i)
		f[i] = f[i - 1] << 1, ++n;
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + f[i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T; init();
	while ( T-- )
	{
		cin >> q;
		cout << lower_bound(f + 1, f + n + 1, q) - f - 1 << endl;
	}
	return 0;
}