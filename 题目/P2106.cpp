// Problem:      P2106 Sam数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2106
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-12 18:49:47 

#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int ord = 10;
const i64 mod = 1000000007;

struct Matrix
{
	i64 m[ord][ord] = { 0 };
	Matrix() {}
	inline void init() { memset(m, 0, sizeof m); }
	inline friend Matrix operator * (const Matrix& A, const Matrix& B)
	{
		reg Matrix res;
		for (reg int i = 0; i < ord; ++i)
			for (reg int j = 0; j < ord; ++j)
				for (reg int k = 0; k < ord; ++k)
					res.m[i][j] = (res.m[i][j] + A.m[i][k] * B.m[k][j] % mod) % mod;
		return res;
	}
} ans, base, res;

i64 n, qwp;

inline void init()
{
	if (n == 1) { puts("10"); exit(0); }
	
	for (reg int i = 1; i < ord; ++i)
		res.m[0][i] = 1;
	for (reg int i = 0; i < ord; ++i)
		ans.m[i][i] = 1;
	
	for (reg int i = 0; i < ord; ++i)
		for (reg int j = max(0, i - 2); j <= min(ord - 1, i + 2); ++j)
		// for (reg int j = max(0, i - 2); j <= min(ord, i + 2); ++j)
			base.m[i][j] = 1;
}

inline i64 Matrixfpow(i64 p)
{
	i64 faq = 0;
	while (p)
	{
   		if (p & 1) ans = ans * base;
		base = base * base;
		p >>= 1;
	}
	res = res * ans;
	for (reg int i = 0; i < ord; ++i)
		faq = (faq + res.m[0][i]) % mod;
	return faq;
}

int main()
{
	cin >> n; init();
	cout << Matrixfpow(n - 1) << endl;
	return 0;
}