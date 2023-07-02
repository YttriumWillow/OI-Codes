#include <iostream>

#include <cstring>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

struct Frac
{
	i64 u, d;
	Frac() {}
	Frac(i64 _u, i64 _d): u(_u), d(_d) {}
	inline void print() { cout << u << '/' << d << endl; }
} fib[110];

i64 n, ans = 1;

int main()
{
	cin >> n;
	if (n == 1) { Frac(1, 1).print(); return 0; }
	fib[0] = Frac(1, 1); fib[1] = Frac(1, 1);
	for (reg int i = 2; i <= 92; ++i)
		fib[i] = Frac(fib[i - 1].d, fib[i - 1].u + fib[i - 1].d);
	while (fib[ans].d <= n && ans <= 91)
		++ans;
	fib[ans - 1].print();
	return 0;
}