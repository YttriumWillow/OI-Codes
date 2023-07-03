// Problem:      64位整数乘法
// Contest:      AcWing
// URL:          https://www.acwing.com/problem/content/92/
// Memory Limit: 32 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-02 21:22:10 

#include <iostream>

#define i64 long long
#define i128 __int128
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

template<typename Tp>
inline void read(Tp &x)
{
	#define gc getchar
	x = 0; int sgn = 1; char ch = gc();
	for (; !isdigit(ch); ch = gc()) if (ch == '-') sgn = -1;
	for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
	x *= sgn;
}

i128 a, b, mod;
i64 res;

int main()
{
	read(a); read(b); read(mod);
	a *= b; res = a % mod;
	cout << res << endl;
	return 0;
}