// Problem:      P3376 【模板】网络最大流
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3376
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-10 19:49:14 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int tot = 1, head[N];
struct Edge
{
	int v, nxt; i64 w;
	Node() { }
	Node(int v, i64 w, int nxt): v(v), nxt(nxt), w(w) { }
}
inline void addedge(int u, int v, int w)
{ e[++tot] = Edge(v, w, head[u]); head[u] = tot; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> s >> t;
	
	return 0;
}