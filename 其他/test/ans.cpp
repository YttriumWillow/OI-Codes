#include <iostream>

using namespace std;

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.ans", "w", stdout);
	int a, b;
	while (cin >> a >> b)
	{
		cout << a + b << endl;
	}
	return 0;
}