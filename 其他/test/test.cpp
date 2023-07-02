#include <iostream>

#define ull unsigned long long

using namespace std;

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	ull a, b;
	while (cin >> a >> b)
	{
		cout << a + b << endl;
	}
	return 0;
}