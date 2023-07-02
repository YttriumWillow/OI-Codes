// Problem:      P2073 送花
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2073
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-26 16:27:10 

#include <iostream>
#include <set>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

struct Node
{
	i64 w, c;
	friend bool operator < (const Node& _x, const Node& _y)
	{ return _x.c < _y.c; }
};

i64 w, c, opt;
i64 res1, res2;
set< Node > s;

int main()
{
	while (~scanf("%lld", &opt))
	{
		if (opt == 1)
		{
			scanf("%lld%lld", &w, &c);
			s.insert({ w, c });
		}
		if (opt == 2)
		{
			if (!s.empty()) s.erase(--s.end());
		}
		if (opt == 3)
		{
			if (!s.empty()) s.erase(s.begin());
		}
		if (opt == -1)
		{
			for (auto x : s) res1 += x.w, res2 += x.c;
			printf("%lld %lld\n", res1, res2); exit(0);
		}
	}
	return 0;
}