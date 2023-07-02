// Problem:      T324104 『XYGOI round1』三个数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T324104?contestId=113611
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-01 14:03:02 

#include <iostream>

#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 LMT = 1e12;
const int N  = 114514;

i64 T, n, v, q;

i64 sum[N] = { 0, 0, 1, 3 };
i64 f[N] = { 0, 0, 1, 2 };

inline void init()
{
	for (int i = 4; i <= 40; ++i)
	{
		f[i] = sum[i - 1];
		sum[i] = sum[i - 1] + f[i];
	}
	n = 40;
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