// Problem:      P6510 奶牛排队
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6510
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-04 10:06:57 

#include <iostream>

#include <stack>
#include <vector>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define push push_back
#define pop pop_back
#define top back

using namespace std;

int n, ans;
int a[1000010];

vector<int> stmax;
vector<int> stmin;

int main()
{
	scanf("%d", &n);
	for (reg int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (reg int i = 1; i <= n; ++i)
	{
		// clean
		while (!stmin.empty() && a[stmin.top()] >= a[i])
			stmin.pop();
		while (!stmax.empty() && a[stmax.top()] < a[i])
			stmax.pop();
		// find
		auto k = lower_bound(stmin.begin(), stmin.end(), (stmax.empty() ? 0 : stmax.top()) );
		if (k != stmin.end())
			ans = max(ans, i - *k + 1);
		// add
		stmin.push(i);
		stmax.push(i);
	}
	printf("%d\n", ans);
	return 0;
}