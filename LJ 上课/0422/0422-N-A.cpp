#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, cnt;
int sum[2010];
int a[2010];
int C[2010][3];

inline bool check(int i, int j)
{
	int x = sum[j] - sum[i];
	int y = sum[i] + sum[n] - sum[j];
	// if (i == 3 && j == 7)
		// cerr << "check: " << i << ' ' << j << endl,
		// cerr << "value: " << x << ' ' << y << endl;
	return x == y;
}

inline void init(int n)
{
	for (reg int i = 1; i <= n; ++i)
		C[i][0] = 1;
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = 1; j <= 2; ++j)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	// for (reg int i = 1; i <= n; ++i)
		// for (reg int j = 1; j <= 2; ++j)
			// cerr << C[i][j] << " \n"[j == 2];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n; init(n);
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i], sum[i] = sum[i - 1] + a[i];
	// for (reg int i = 1; i <= n; ++i)
		// cerr << i << " \n"[i == n];
	// for (reg int i = 1; i <= n; ++i)
		// cerr << sum[i] << " \n"[i == n];
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = i + 1; j <= n; ++j)
			if (check(i, j))
				++cnt;
	cout << C[cnt + 1][2] << endl;
	return 0;
}