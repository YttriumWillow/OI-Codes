// Problem:      Product Oriented Recurrence
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF1182E
// Memory Limit: 250 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-02 14:13:05 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 1e9 + 7;
const int ord3 = 4;
const int ord5 = 6;

struct Matrix3
{
	int m[3][3] = { 0 };
	inline void to1() { for (int i = 0; i < 3; ++i) m[i][i] = 1; }
	inline void place(int a[][])
	{
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				m[i][j] = a[i][j];
	}
	inline friend Matrix3 operator * (Matrix3 &a, Matrix3 &b)
	{
		Matrix res;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
					res.m[i][j] = (res.m[i][j] + 
						1ll * a.m[i][k] * b.m[k][j] % mod) % mod;
		return res;
	}
};
struct Matrix5
{
	int m[5][5] = { 0 };
	inline void to1() { for (int i = 0; i < 5; ++i) m[i][i] = 1; }
	inline void place(int a[][])
	{
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				m[i][j] = a[i][j];
	}
	inline friend Matrix5 operator * (Matrix5 &a, Matrix5 &b)
	{
		Matrix res;
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j)
				for (int k = 0; k < 5; ++k)
					res.m[i][j] = (res.m[i][j] + 
						1ll * a.m[i][k] * b.m[k][j] % mod) % mod;
		return res;
	}
};
template <typename Tp>
inline Tp pow(Tp a, i64 k)
{
	Tp res; res.to1();
	for (; k; k >>= 1)
	{
		if (k & 1) res = res * a;
		a = a * a;
	}
	return a;
}
inline int fpow(int a, i64 k)
{
	int res; res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
	}
	return res;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> f1 >> f2 >> f3 >> c;
	
	Matrix5 f;
	
	return 0;
}