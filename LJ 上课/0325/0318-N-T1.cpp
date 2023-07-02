#include <iostream>

#include <iomanip>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, h[310];
int high, low;
long double A[310][310];
long double ans;
long double tmp;

inline void init(int n)
{
	for (reg int i = 0; i <= n; ++i)
		A[i][0] = 1;
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = 1; j <= i; ++j)
			A[i][j] = A[i][j - 1] * (i - j + 1);
	tmp = 1;
	for (reg int i = 1; i <= n; ++i)
		tmp *= i;
}

int main()
{	
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> h[i];
	
	init(n);
	
	for (reg int i = 1; i <= n; ++i)
	{
		high = low = 0;
		for (reg int j = 1; j <= n; ++j)
			high += (h[j] >= h[i] && i != j);
		low = n - 1 - high;
		
		for (reg int j = 1; j <= n; ++j)
		{
			ans += A[low][j - 1] * A[n - j][n - j] * j;
			for (reg int k = 1; k <= j - 1; ++k)
				ans += A[high][1] * A[low][k - 1] * A[n - k - 1][n - k - 1] * k;
		}
	}
	cout << fixed << setprecision(2) << ans / tmp << endl;
	return 0;
}