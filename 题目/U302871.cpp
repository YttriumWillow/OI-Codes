// Problem:      U302871 公约数的和
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/U302871?contestId=108475
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-07-01 20:34:26 

// 随机化，启动！

#include <iostream>

#include <random>
#include <algorithm>
#include <ctime>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e6 + 10;
const int mod = 1e9 + 7;

int n, x, a[N], ans;

inline void play()
{
	while (next_permutation(a + 1, a + n + 1))
	{
		int res = a[1];
		for (int i = 2; i <= x; ++i)
	    	res = __gcd(res, a[i]);
  		ans = (ans + res) % mod;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	play();
	cout << ans << endl;
	return 0;
}