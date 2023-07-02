// Problem:      T324977 不死「徐福时空」
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T324977?contestId=105752
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-09 20:50:44 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, d;
int cost;
int a[100010];

inline void shell(const int d)
{
	for (reg int i = 1; i <= d; ++i)
	{
		for (reg int j = 1; j <= n; j += d)
		{
			int faq = a[j], pos = j;
			for (reg int k = j; k <= n; k += d)
				if (a[k] < faq)	{ pos = k; faq = a[k]; }
			for (reg int k = pos; k >= j + d; k -= d)
				swap(a[k], a[k - d]);
			// if (pos != j) 
			cost += abs(pos - j) + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i];
	while (m--)
	{
		cin >> d;
		shell(d);
	}
	cout << cost << endl;
	for (reg int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	return 0;	
}