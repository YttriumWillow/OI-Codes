// Problem:      P1298 最接近的分数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1298
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-06 08:09:14 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const double eps = 1e-13;

int m, n;
double R;

#define dif(q) abs(q-R)

struct Frac
{
	int u, d;
	Frac() {}
	Frac(int _u, int _d): u(_u), d(_d) {}
	inline void reduct() { int tmp = __gcd(u, d); u /= tmp, d /= tmp; }
	inline void rev() { swap(d, u); }
	inline double real() { return u * 1.0 / d; }
	inline void print() { reduct(); cout << u << '/' << d << endl; }
};

	// return (dif(l * 1.0 / i) < dif(r * 1.0 / i));

Frac ans = Frac(0, 1);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> m >> n >> R;
	for (reg int i = 1; i <= n; ++i)
	{
		reg int l = 1, r = m;
		while (r - l > 2)
		{
			reg int m1 = l + (r - l) / 3;
			reg int m2 = r - (r - l) / 3;
			if (dif(m1 * 1.0 / i) < dif(m2 * 1.0 / i))
				r = m2;
			else
				l = m1;
		}
		if ( dif(l * 10 / i) < dif(ans.real()) )
			ans = Frac(l, i);
		if ( dif(r * 1.0 / i) < dif(ans.real()) )
			ans = Frac(r, i);
		reg int mid = (l + r) >> 1;
		if ( dif(mid * 1.0 / i) < dif(ans.real()) )
			ans = Frac(mid, i);
	}
	ans.print();
	return 0;
}