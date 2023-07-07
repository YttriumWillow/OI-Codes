#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e3 + 10;

int n;
int a[N][N];

inline void Solve(int n)
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
			// if (i + j > n + 1)
				// a[4 - j][4 - i] += a[i][j];
		}
	cout << n << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin >> n && n)
		Solve(n);
	return 0;
}