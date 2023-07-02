// Problem:      U307919 简单数据结构题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/U307919?contestId=115417
// Memory Limit: 128 MB
// Time Limit:   2000 ms
// Created Time: 2023-06-29 18:55:59 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

int n, m, x, y;
int l, r;
i64 a[N];
i64 fib[N];

inline void init(int n, int x, int y)
{
	fib[1] = fib[2] = 1;
	for (int i = 3; i <= n; ++i)
		fib[i] = (x * fib[i - 1] + y * fib[i - 2]) % mod;
}

inline void modify(int l, int r)
{
	static int i; i = l;
	for (; i + 4 <= r; i += 4)
	{
		
		a[i + 0] = ( a[i + 0] + fib[i - l + 1] ) % mod;
		a[i + 1] = ( a[i + 1] + fib[i - l + 2] ) % mod;
		a[i + 2] = ( a[i + 2] + fib[i - l + 3] ) % mod;
		a[i + 3] = ( a[i + 3] + fib[i - l + 4] ) % mod;
		
	}
	for (; i <= r; ++i)
		a[i] = ( a[i] + fib[i - l + 1] ) % mod;
}

// inline void debug()
// {
	// for (int i = 1; i <= n; ++i)
		// cerr << a[i] << " \n"[i == n];
// }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> x >> y;
	init(n, x, y);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
	{
		cin >> l >> r;
		modify(l, r);
		// debug();
	}
	for (int i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	
	return 0;
}