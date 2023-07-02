// Problem:      Problem 1. Hungry Cow
// Contest:      USACO - USACO 2023 February Contest, Bronze
// URL:          http://usaco.org/index.php?page=viewproblem&cpid=1287
// Memory Limit: 256 MB
// Time Limit:   4000 ms
// Created Time: 2023-02-25 10:05:42 

#include <iostream>

#include <map>
#include <algorithm>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define date first
#define val second 

using namespace std;

map<int, int> m;
vector<int> d;

i64 n, k, now;
i64 day, num;

int main()
{
	scanf("%d%d", &n, &t);
	for (reg int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &day, &num);
		m[day] += num;
	}
	auto i, j;
	i = m.begin(); j = m.begin();
	now += (*i).val;
	for (++j; j != m.end(); ++i, ++j)
	{
		
		now -= (*j).date - (*i).date + 1;
	}
	return 0;
}