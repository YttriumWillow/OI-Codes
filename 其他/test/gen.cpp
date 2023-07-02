#include <iostream>

#define reg register

using namespace std;

int main()
{
	int tim;
	freopen("a.in", "w", stdout);
	tim = rand();
	for (reg int i = 1; i <= tim; ++i)
		cout << rand() << ' ' << rand() << endl;
	return 0;
}