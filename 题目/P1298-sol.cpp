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

const double eps = 2e-15;

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

int m, n;
long double R;
int x, y, p, q, cnt;
int xp, yq;
long double xp_yq;
bool fnd;
Frac ans = Frac(0, 1);

#define dif(q) abs(q-R)

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> m >> n >> R;
	// x / y < (x + p) / (y + q) < p / q
	x = 0, y = 1, p = (int)R + 1, q = 1;
	while (1)
	{
		int gxy = __gcd(x, y);
		int gpq = __gcd(p, q);
		x /= gxy, y /= gxy;
		p /= gpq, y /= gpq;
		xp = x + p; yq = y + q;
		xp_yq = xp * 1.0 / yq;
		// cerr << x << '/' << y << '<' << p << '/' << q << endl; 
		// cerr << xp << ' ' << yq << '=' << xp_yq << endl;
		if ((xp > m || yq > n) && fnd) break;
		if (xp_yq < R) x = xp, y = yq;
		else           p = xp, q = yq;
		if (dif(xp_yq) <= eps)
			++cnt, ans = Frac(xp, yq);
		else
			cnt = 1; 
		fnd = 1;
	}
	if (dif(x * 1.0 / y) < dif(p * 1.0 / q))
		ans = Frac(x, y);
	else
		ans = Frac(p, q);
	if (cnt > 1)
		puts("TOO MANY");
	else
		ans.print();
	return 0;
}














