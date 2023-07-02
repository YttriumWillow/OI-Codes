#include <iostream>

#include <algorithm>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

i64 ax, ay, bx, by;
i64 ricardo, xshen;

u64 gcd(u64 a, u64 b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

u64 sub(i64 a, i64 b)
{
	if(a < b) swap(a, b);
	
	if(a >= 0 && b <= 0) {
		u64 x = a, y = -b;
		return x + y;
	}
	if(a >= 0 && b > 0) return a - b;
	if(a < 0 && b <= 0) return sub(-b, -a);
}

inline bool check(i64 ax, i64 ay, i64 bx, i64 by)
{
	u64 dx = sub(bx, ax);
	u64 dy = sub(by, ay);
	if (dx == 0 && dy == 0) return 1;
	return (gcd(dx, dy) == 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin >> ax >> ay >> bx >> by)
	{
		if (check(ax, ay, bx, by))
			cout << "YE5" << endl, ++ricardo;
		else
			cout << "NO" << endl, ++xshen;
	}
	if (ricardo > xshen)
		cout << "Poor xshen!" << endl;
	else if (ricardo == xshen)
		cout << "Friend Ship." << endl;
	else
		cout << "Yahoo!" << endl;
	return 0;
}