#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 mod = 998244353;

i64 op, n, T, k, faq;

inline i64 fpow(i64 a, i64 p)
{
	i64 base = a, res = 1; 
	while (p)
    {
		if (p & 1)
			res = (base * res) % mod;
		base = (base * base) % mod;
		p >>= 1;
    }
    return res;
}

inline i64 inv(i64 a) { return fpow(a, mod - 2); }

inline void read(i64& x1, i64& x2)
{
	x1 = x2 = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar());
	for (; isdigit(ch); ch = getchar())
	{
		x1 = x1 * 10 % mod + (ch ^ '0');
		x2 = x2 * 10 % (mod - 1) + (ch ^ '0');
	}	
	x1 %= mod; x2 %= (mod - 1);
}

int main()
{
    cin >> op;
    if (op == 1)
    {
        read(n, faq); cin >> k;
        i64 p = fpow(2, (faq + mod - 2) % (mod - 1));
        cout << (p - n + mod) % mod * inv(p) % mod;
    }
    if (op == 2)
    {
        cin >> T;
        while (T--)
        {
            cin >> n;
            if (n == 1)
                cout << "cqz" << endl;
            else
                cout << "ysgh" << endl;
        }
    }
    return 0;
}