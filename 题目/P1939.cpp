// Problem:      P1939 【模板】矩阵加速（数列）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1939
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-04 14:40:48 

#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int order = 3;
const i64 mod = 1e9 + 7;

i64 n, T;

struct Matrix
{
	i64 m[order + 1][order + 1] = {0};
	void init() { memset(m, 0, sizeof(m)); }
	void set() { for (reg int i = 1; i <= order; ++i) m[i][i] = 1; }
	friend Matrix operator * (const Matrix& A, const Matrix& B)
	{
		Matrix res;
		for (reg int i = 1; i <= order; ++i)
			for (reg int j = 1; j <= order; ++j)
				for (reg int k = 1; k <= order; ++k)
					res.m[i][j] = (res.m[i][j] + ((A.m[i][k] % mod) * (B.m[k][j] % mod)) % mod) % mod;
					// res.m[i][j] %= mod;
		return res;
	}
} base, ans;

inline void MatrixQuickPow(int p)
{
	while (p)
	{
		if (p & 1) ans = ans * base;
		base = base * base;
		p >>= 1;
	}
}

void init()
{
	base.init();
	ans.init();
	ans.set();
	base.m[1][1] = base.m[1][3] = base.m[2][1] = base.m[3][2] = 1;
}

int main()
{
	scanf("%lld", &T);
	while (T--)
	{
		scanf("%lld", &n);
		if (n <= 3) { printf("1\n"); continue; }
		init();
		MatrixQuickPow(n);
		printf("%lld\n", ans.m[2][1]);
	}
	return 0;
}