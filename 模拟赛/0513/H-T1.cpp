#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 m = 998244353;
const i64 mod = 1000000007;
const i64 inf = 0x7ffffffffffff;

int n;
i64 a[100010];

inline i64 f(int l, int r)
{
	i64 res = 0;
	for (reg i64 i = r; i >= l; --i)
		res = (res * m + a[i]) % mod;
	return res;
}

inline i64 g(int len)
{
	i64 res = inf;
	for (reg int r1 = len; r1 < n; ++r1)
		for (reg int r2 = r1 + 1; r2 <= n; ++r2)
			res = min(res, 
			abs( (f(r1 - len + 1, r1) - f(r2 - len + 1, r2) + mod) % mod ) % mod );
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i];
	for (reg int i = 1; i <= n - 1; ++i)
		cout << g(i) << ' ';
	return 0;
}