#include <iostream>

#include <ctime>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e6 + 10;

i64 n, S, T;
i64 w[N];
i64 v[N];

inline i64 calc(i64 wtf)
{
	i64 sum = 0, res = 0;
	for (int i = 1; i <= n; ++i)
		if (sum + w[i] <= wtf)
			sum = sum + w[i], res = res + v[i];
    return res;
}

inline void range()
{
	
}

inline void Solve()
{
	cin >> n >> S;
	
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	
	for (int i = 1; i <= n; ++i)
	{
		
	}
}

int main()
{
	srand(time(0));
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> T;
	while (T--)
		Solve();
	return 0;
}