// Problem:      Sereja and Swaps
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF425A
// Memory Limit: 250 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-04 19:43:39 

#include <iostream>

#include <queue>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 inf = 0xfffffffffffffff;

priority_queue<int, vector<int>, greater<int>> in;
priority_queue<int, vector<int>, less<int>> out;

int n, k;
int a[210];
i64 ans = -inf;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> k;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i];
	for (reg int l = 1; l <= n; ++l)
		for (reg int r = l; r <= n; ++r)
		{
			for (reg int i = l; i <= r; ++i)
				in.push(a[i]);
			for (reg int i = 1; i < l; ++i)
				out.push(a[i]);
			for (reg int i = r + 1; i <= n; ++i)
				out.push(a[i]);
			for (reg int i = 1; i <= k; ++i)
			{
				if (!out.empty() && !in.empty() && in.size() <= (r - l + 1))
				{
					in.push(out.top());
					out.pop(), in.pop();
				}
				else break;
			}
			i64 res = 0;
			while (!in.empty())
				res += in.top(), in.pop();
			while (!out.empty())
				out.pop();
			ans = max(res, ans);
		}
	cout << ans << endl;
	return 0;
}