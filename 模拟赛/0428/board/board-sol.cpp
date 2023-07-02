#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 1e9 + 7;

namespace Math
{
	int fac[100010];
	int invfac[100010];
	
	inline int fpow(int base, int p)
	{
		int res = 1;
		for (; p; p >>= 1)
		{
			if (p & 1) res = res * base % mod;
			base = base * base % mod;
		} return res;
	}
	
	inline int inv(int x) { return fpow(x, mod - 2); }
	
	inline void init(int n)
	{
		fac[0] = 1;
		for (reg int i = 1; i <= n; ++i)
			fac[i] = fac[i - 1] * i % mod;
		invfac[n] = inv(fac[n]);
		for (reg int i = n - 1; ~i; --i)
			invfac[i] = invfac[i + 1] * (i + 1) % mod;
	}
	inline int C(int m, int n)
	{ return fac[m] * invfac[n] % mod * invfac[m - n] % mod; }
}

int main()
{
	inline void 
	return 0;
}