// Problem:      P4000 斐波那契数列
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4000
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-03 20:13:59 

#include <iostream>

#include <cstring>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int ord = 2;

i64 n, mod;

template<typename _Tp>
inline void read(_Tp &x)
{
	x = 0; char ch = getchar(); _Tp sgn = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn = -1;
	for (; isdigit(ch); ch = getchar()) x = (x * 10 + (ch ^ 48)) % mod;
	x *= sgn;
}

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
	cin >> n; cin >> mod; init();
	if (n == 1) cout << 1 << endl;
	cout << MatrixQuickPow(n - 1) << endl;
	return 0;
}