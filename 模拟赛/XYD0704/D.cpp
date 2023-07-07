#pragma GCC optimize(2)

#include <iostream>

#include <cmath>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int V = 4e7 + 10;

int T, l, r;
bool tag[V];
int lg[] = { 1, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

inline int faq(int x, int l, int r)
{
	int res = 1; tag[x] = 1;
	int len = (x <= 0 ? 1 : (int)log10(x) + 1);
	for (int k = 1; k <= len - 1; ++k)
	{
		int tmp = x / lg[len];
		x %= lg[len];
		x = x * 10 + tmp;
		if (x >= l && x <= r && !tag[x])
			tag[x] = 1, ++res;
	}
	return (res * (res - 1)) >> 1;
}

inline int calc(int l, int r)
{
	if (r < 10) return 0;
	
	for (int i = l; i <= r; ++i)
		tag[i] =0;
	
	int res = 0;
	for (int i = l; i <= r; ++i)
		if (!tag[i])
			res += faq(i, l, r);
	return res;
}

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> l >> r;
		cout << calc(l, r) << endl;
	}
	return 0;
}