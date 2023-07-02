#pragma GCC optimize(2)

#include <iostream>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int ord = 2;
const int mod = 1e9 + 7;

i64 n;

struct Matrix
{
	int m[ord + 1][ord + 1] = { 0 };
	inline void init() { memset(m, 0, sizeof m); }
	inline void to1()
	{ for (int i = 1; i <= ord; ++i) m[i][i] = 1; }
	inline friend Matrix operator * (Matrix &a, Matrix &b)
	{
		Matrix res;
		for (int i = 1; i <= ord; ++i)
			for (int j = 1; j <= ord; ++j)
				for (int k = 1; k <= ord; ++k)
					res.m[i][j] = (res.m[i][j] + 
						1ll * a.m[i][k] * b.m[k][j] % mod) % mod;
		return res;
	}
};

inline int fpow(i64 k)
{
	Matrix base;
	
	base.m[1][1] = 1; base.m[1][2] = 1;
	base.m[2][1] = 1; base.m[2][2] = 0;
	
	Matrix res; res.to1();
	for (; k; k >>= 1)
	{
		if (k & 1) res = res * base;
		base = base * base;
	}
	
	return res.m[1][1] % mod;
}

int main()
{
	cin >> n;
	if (n == 0) { cout << 0 << endl; return 0; }
	if (n == 1) { cout << 1 << endl; return 0; }
	cout << fpow(n - 1) << endl;
	return 0;
}