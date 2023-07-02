// Problem:	P4447 [AHOI2018初中组]分组
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P4447
// Memory Limit:	125 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-24 20:56:36 

#include <iostream>

#include <map>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define val first
#define num second

using namespace std;

const int inf = 0x7fffffff;

int n, ans = inf;
map<int, int> m;

void cleanUp()
{
	// for (auto x = m.begin(); x != m.end(); ++x)
		// if ((*x).num == 0)
			// m.erase((*x).val);
	auto x = m.begin();
	while (x != m.end() && (*x).num == 0)
		m.erase((*x++).val);
}

int main()
{
	scanf("%d", &n);
	for (reg int i = 1, x; i <= n; ++i)
	{
		scanf("%d", &x);
		++m[x];
	}
	// for (auto x : m)
		// printf("%d %d\n", x.first, x.second);
	while (!m.empty())
	{
		auto i = m.begin();
		auto j = m.begin();
		--(*i).num;
		int cnt = 1;
		for (++j; (*j).val - (*i).val == 1 && j != m.end() && (*i).num < (*j).num; ++i, ++j)
			++cnt, --(*j).num;
		i = m.begin();
		cleanUp();
		ans = min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
