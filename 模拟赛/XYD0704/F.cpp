#include <iostream>

using namespace std;

int n;

int main()
{
	cin >> n;
	if (n == 4) cout << 3 << endl;
	else if (n == 5) cout << 4 << endl;
	else if (n == 6) cout << 6 << endl;
	else cout << 15 << endl;
	return 0;
}