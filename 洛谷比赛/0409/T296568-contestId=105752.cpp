// Problem:      T296568 灭罪「正直者之死」
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T296568?contestId=105752
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-09 20:28:12 

#include <iostream>

#include <ctime>
#include <random>
#include <cmath>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, k, ans, cnt;
int low, high, pos, now;
int a[100010];
bool vis[100010];

inline bool check(const int& x)
{
	return low <= x && x <= high;
}

inline int delta(const int x)
{
	return abs(cnt + x);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	low = -(1 << (k - 1)); 
	high = (1 << (k - 1)) - 1;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (reg int i = 1; i <= n; ++i)
	{
		now = 1e9; pos = 1;
		for (reg int j = 1; j <= n; ++j)
		{
			if (delta(a[j]) < now && !vis[j])
			{
				pos = j;
				now = delta(a[j]);
			}
		}
		if (check(cnt + a[pos]) && !vis[pos])
		{
			vis[pos] = 1;
			cnt += a[pos];
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}