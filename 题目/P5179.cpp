// Problem:      P5179 Fraction
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5179
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-13 18:55:59

#include <iostream>

#include <cmath>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 a, b, c, d;

struct Frac
{
	i64 u, d;
	Frac() {}
	Frac(i64 _u, i64 _d): u(_u), d(_d) {}
	void reduct() { i64 tmp = __gcd(u, d); u /= tmp, d /= tmp; }
	void rev() { swap(d, u); }
	void print() { reduct(); cout << u << '/' << d << endl; }
} ans;

void lgcd(Frac l, Frac r, Frac& res)
{
	l.reduct(); r.reduct();
	if (l.u < l.d && r.u > r.d)
		res.u = res.d = 1;
    else
    {
    	res.rev();
        lgcd(Frac(r.d % r.u, r.u), Frac(l.d - (r.d / r.u) * l.u, l.u), res);
        res.rev(); res.d += (r.d / r.u) * res.u;
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin >> a >> b >> c >> d)
	{
		lgcd(Frac(a, b), Frac(c, d), ans);
		ans.print();
	}
	return 0;
}