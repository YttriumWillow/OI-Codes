// Problem:      P3376 【模板】网络最大流
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3376
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-07 19:24:35 

#include <iostream>

#include <vector>
#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 210;
const int M = 5010;
const int inf = 0x7fffffff;

int head[N];
int v[M], w[M], nxt[M];

inline void addedge(int u, int v, int w)
{
	v[++tot] = v;
	w[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot;
}

inline bool bfs()
{
	memset(lst, -1, sizeof lst)
}

inline int EK()
{
	int res = 0;
	while (bfs())
	{
		res += flow[t];
		for (reg int i = t; i != s; i = v[lst[i] ^ 1])
		{
			w[lst[i]] -= flow[t];
			w[lst[i] ^ 1] += flow[t];
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> s >> t;
	for (reg int i = 1; i <= m; ++i)
		
	return 0;
}