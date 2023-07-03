// Problem:      P2044 [NOI2012] 随机数生成器
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2044
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-03 10:40:43 

#include <iostream>

#include <cstring>

#define i64 long long
#define i128 __int128
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int ord = 2;

template<typename Tp>
inline void read(Tp &x)
{
	#define gc getchar
	x = 0; int sgn = 1; char ch = gc();
	for (; !isdigit(ch); ch = gc()) if (ch == '-') sgn = -1;
	for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
	x *= sgn;
}

i128 a, c, n;
i128 x0, x1;
i128 mod, g;

struct Matrix
{
	i128 m[3][3] = { 0 };
	Matrix() {}
	Matrix(int b)
	{
		if (b == 1)
		{
			m[1][1] = x0; m[1][2] = c;
		}
		if (b == 2)
		{
			m[1][1] = a, m[1][2] = 0;
			m[2][1] = 1, m[2][2] = 1;
		}
	}
	inline friend Matrix operator * (Matrix &a, Matrix &b)
	{
		Matrix res;
		for (int i = 1; i <= ord; ++i)
			for (int j = 1; j <= ord; ++j)
				for (int k = 1; k <= ord; ++k)
					res.m[i][j] = (res.m[i][j] + 
						a.m[i][k] * b.m[k][j] % mod) % mod;
		return res;
	}
};

inline i64 fpow(i128 k)
{
	Matrix res(1), a(2);
	for (; k; k >>= 1)
	{
		if (k & 1)	
			res = res * a;
		a = a * a;
	}
	return res.m[1][1] % g;
}

int main()
{
	read(mod); read(a); read(c); read(x0); read(n); read(g);
	
	x1 = (a * x0 + c) % mod;
	if (n == 0) { cout << (i64)(x0 % mod) << endl; return 0; }
	if (n == 1) { cout << (i64)(x1 % mod) << endl; return 0; }
	
 	cout << fpow(n) << endl;
	return 0;
}