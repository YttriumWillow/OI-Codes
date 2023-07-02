#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;
int a[1010];
int b[1010];

namespace Subtask1
{
	inline void solve()
	{
		cout << 1 << endl;
		cout << 1 << ' ' << b[1] - 1 << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> b[i];
	if (n == 1) Subtask1::solve();
	else qwq
	return 0;
}