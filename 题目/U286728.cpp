// Problem:      U286728 平凡序列变换题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/U286728?contestId=115417
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-29 19:19:04 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int L = 1e2 + 10;
const int N = 5e4 + 10;

i64 n, k, T, t;

int p[L][N];
int a[2][N], now;
int change[N];

inline bool check(int g)
{
	for (int i = 1; i <= n; ++i)
		if (a[g][i] - a[g][i - 1] != 1)
			return false;
	return true;
}

inline void cheat(i64 qaq)
{
	int edd = k % qaq, now = 0;
	// cerr << qaq << endl;
	
	for (int i = 1; i <= n; ++i)
		a[1][i] = i;
	for (int t = 1; t <= edd; ++t, now ^= 1)
		for (int i = 1; i <= n; ++i)
			a[now][i] = a[now ^ 1][change[i]];
	
	for (int i = 1; i <= n; ++i)
		cout << a[now ^ 1][i] << ' ';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k >> T;
	for (int t = 1; t <= n; ++t)
		for (int i = 1; i <= n; ++i)
			cin >> p[t][i];
	
	for (int i = 1; i <= n; ++i)
		a[1][i] = i;
	for (int t = 1; t <= T; ++t, now ^= 1)
		for (int i = 1; i <= n; ++i)
			a[now][i] = a[now ^ 1][ p[t][i] ];
	for (int i = 1; i <= n; ++i)
		change[i] = a[now ^ 1][i];
		
	if (check(now ^ 1))
	{
		for (int i = 1; i <= n; ++i)
			cout << i << ' ';
		exit(0);
	}
	
	for (int x = 2; x <= k; ++x, now ^= 1)
	{
		for (int i = 1; i <= n; ++i)
			a[now][i] = a[now ^ 1][change[i]];
		if (check(now)) cheat(x), exit(0);
	}
	
	for (int i = 1; i <= n; ++i)
		cout << a[now ^ 1][i] << ' ';
	return 0;
}


		// for (int i = 1; i <= n; ++i)
			// cerr << a[now][i] << " \n"[i == n];