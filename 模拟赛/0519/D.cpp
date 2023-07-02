#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx512f,sse4.1,sse4.2")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 51;

// inline void dfs(int l, r)

int n, a, b;
int w[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	cout << a + b << endl;
	return 0;
}