#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, a, b, ans;

int main()
{
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
	{
		cin >> a >> b;
		ans += min(a, b);
	}
	cout << ans << endl;
	return 0;
}