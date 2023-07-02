// Problem:      P5170 【模板】类欧几里得算法
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5170
// Memory Limit: 125 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-19 18:56:02 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 mod = 998244353;
const i64 inv2 = 499122177;
const i64 inv6 = 166374059;

struct FAQ { i64 f = 0, g = 0, h = 0; };

inline FAQ lgcd(i64 a, i64 b, i64 c, i64 n)
{
	FAQ res;
	i64 n1 = n + 1, n21 = 2 * n + 1;
	i64 ac = a / c, bc = b / c;
	if (a == 0)
	{
		res.f = bc * n1 % mod;
		res.g = bc * n % mod * n1 % mod * inv2 % mod;
		res.h = bc * bc % mod * n1 % mod;
		return res;
	}
	if (a >= c || b >= c)
	{
		FAQ t = lgcd(a % c, b % c, c, n);
		res.f = (n * n1 % mod * inv2 % mod * ac % mod
			  + n1 * bc % mod + t.f) % mod;
		res.g = (n * n1 % mod * n21 % mod * inv6 % mod * ac % mod
			  + n * n1 % mod * inv2 % mod * bc % mod + t.g) % mod;
		res.h = (n * n1 % mod * n21 % mod * inv6 % mod * ac % mod * ac % mod
			  + n1 * bc % mod * bc % mod + ac * bc % mod * n % mod * n1 % mod
			  + 2 * ac % mod * t.g % mod + 2 * bc % mod * t.f % mod) % mod;
		return res;
	}
	i64 m = (a * n + b) / c;
	FAQ t = lgcd(c, c - b - 1, a, m - 1);
	res.f = (n * m % mod - t.f + mod) % mod;
	res.g = (m * n % mod * n1 % mod - t.h - t.f + mod) % mod
		  * inv2 % mod;
	res.h = (n * m % mod * (m + 1) % mod - 2 * t.g 
		  - 2 * t.f - res.f + mod) % mod;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	i64 T;
	cin >> T;
	while (T--)
	{
		i64 a, b, c, n;
		cin >> n >> a >> b >> c;
		FAQ res = lgcd(a, b, c, n);
		cout << res.f << ' ' << res.h << ' ' << res.g << endl;
	}
	return 0;
}