// Problem:      T334143 奥拓普雷
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T334143
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-03 21:01:21 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N];
i64 ans1, ans2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= m; ++i)
		cin >> a[i];
	for (reg int i = 1; i <= m; ++i)
	{
		if (n <= 2)
			(i % 2) ? ans1 += a[i] : ans2 += a[i];
		else if (a[i] > 0)
			(i % 2) ? ans1 += a[i] : ans2 += a[i];
	}
	cout << max(ans1, ans2) << endl;
	return 0;
}