// Problem:      P1306 斐波那契公约数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1306
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-03 20:13:20 

#include <iostream>

#include <cstring>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int ord = 2;
const i64 mod = 19491001;

struct Matrix
{
	i64 a[ord + 1][ord + 1] = { 0 };
	inline void init() { memset(a, 0, sizeof a); }
	inline friend Matrix operator * (const Matrix& A, const Matrix& B)
	{
		Matrix res;
		for (reg int i = 1; i <= ord; ++i)
			for (reg int j = 1; j <= ord; ++j)
				for (reg int k = 1; k <= ord; ++k)
					res.a[i][j] = (res.a[i][j] + (A.a[i][k] * B.a[k][j]) % mod) % mod;
		return res;
	}
};

i64 n, m, T;
Matrix base, ans;

inline void init()
{
	ans.init(); base.init();
	 ans.a[1][1] = 1;  ans.a[2][1] = 1;
	base.a[1][1] = 1; base.a[1][2] = 1;
	base.a[2][1] = 1; base.a[2][2] = 0;
}

inline i64 MatrixQuickPow(i64 p)
{
	while (p)
	{
		if (p & 1)
			ans = ans * base;
		base = base * base;
		p >>= 1;
	}
	return ans.a[1][1] % mod;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m; init();
		cerr << __gcd(n, m) << endl;
		cout << MatrixQuickPow(__gcd(n, m) - 1) << endl;
	}
	return 0;
}