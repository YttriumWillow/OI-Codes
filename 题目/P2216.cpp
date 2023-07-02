// Problem:      P2216 [HAOI2007]理想的正方形
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2216
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-04 10:41:57 

#include <iostream>

#include <ctime>
#include <random>

#define i64 long long
#define reg register
#define qwq printf("fzy qwq ~\n");

using namespace std;

const double timelimit = 1 * 0.97;
const int inf = 0x7fffffff;

int n;
int a, b, ans = inf;
int m[1010][1010];
bool vis[1010][1010];
time_t st = clock();

inline void work()
{
	int nowmax = -inf, nowmin = inf;
	int x = rand() % (a - n + 1) + 1, y = rand() % (b - n + 1) + 1;
	if (vis[x][y]) return ;
	vis[x][y] = 1;
	for (reg int i = x; i < x + n; ++i)
		for (reg int j = y; j < y + n; ++j)
			nowmax = max(nowmax, m[i][j]),
			nowmin = min(nowmin, m[i][j]);
	if (ans >= nowmax - nowmin)
		ans = nowmax - nowmin;
}

int main()
{
	srand(114514 & 1919810);
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 1; i <= a; ++i)
		for (reg int j = 1; j <= b; ++j)
			scanf("%d", &m[i][j]);
	while (clock() - st < timelimit * CLOCKS_PER_SEC)
		work();
	printf("%d\n", ans);
	return 0;
	qwq
}