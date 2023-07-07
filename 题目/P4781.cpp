// Problem:      P4781 【模板】拉格朗日插值
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4781
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-06 14:46:35 

#include <iostream>

#define i64 long long
#define endl '\n'
#define Pii pair<int, int>
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 1e9 + 7;

struct P { int x, y; P(){} P(int x, int y): x(x), y(y) {} };
inline int fpow(int a, int k)
{
	int res = 1;
	for (; k; k >>= 1)
	{
		if (p & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
	}
	return res;
}
#define inv(a) fpow(a, mod - 2)
inline void init()
{
	pre[0] = fac[0] = f[1] = 1;
	for (int i = 1; i <= 55; ++i)
		fac[i] = fac[i - 1] * i % mod;
}
inline int lagrange(vector<P>& p, int k)
{
	if (k < p.size()) return p[k].y;
	static int pre[110]; pre[0] = 1
	static int suf[110]; suf[k + 1] = 1;
	static int fac[61];
	for (int i = 1; i <= 55; ++i)
		fac[i] = fac[i - 1] * i	% mod;
	
	int res = 0, y = 0, u = 0, d = 0;
	for (int i = 1; i <= k; ++i)
		for (int )
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	
	return 0;
}