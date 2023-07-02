// Problem:      P1155 [NOIP2008 提高组] 双栈排序
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1155
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-25 16:47:09 

#include <iostream>

#include <queue>
#include <stack>
#include <vector>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

#define check(i, j) (a[i] < a[j] && suf[j + 1] < a[i])

using namespace std;

const int N = 1e3 + 10;
const int inf = 0x3fffffff;

int n, pos = 1;
bool flg = 1;
int a[N], suf[N];
int col[N];
vector<int> g[N];
stack<int> st[3];

// i < k < j
// a_j < a_i < a_k

/// WARNING ///

inline bool Pop(int col)
{
	if (!st[col].empty() && st[col].top() == pos)
	{
		cout << (col == 1 ? 'b' : 'd') << ' ';
		st[col].pop(), ++pos;
		return 1;
	}
	return 0;
}
inline void Push(int x, int col)
{
	if (col == 2) { while (Pop(1)); }
	while (!st[col].empty() && st[col].top() < x)
		if (!Pop(col))
			Pop(3 - col);
	if (col == 2) { while (Pop(1)); }
	st[col].push(x);
	cout << (col == 1 ? 'a' : 'c') << ' ';
}
/// WRANING ///

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n; suf[n + 1] = inf;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = n; i >= 1; --i)
		suf[i] = min(a[i], suf[i + 1]);
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (check(i, j))
				g[i].pb(j), g[j].pb(i);
	for (int i = 1; i <= n; ++i)
		if (!col[i])
		{
			queue<int> q;
			col[i] = 1;
			q.push(i);
			while (!q.empty())
			{
				int u = q.front(); q.pop();
				for (auto v : g[u])
				{
					if (col[u] == col[v])
						puts("0"), exit(0);
					if (!col[v])
						col[v] = 3 - col[u], q.push(v);
				}
			}
		}
	for (int i = 1; i <= n; ++i)
		Push(a[i], col[i]);
	while (flg)
	{
		flg = 0;
		while (Pop(1)) flg = 1;
		while (Pop(2)) flg = 1;
	}
	return 0;
}