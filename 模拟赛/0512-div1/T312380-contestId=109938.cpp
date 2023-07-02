// Problem:      T312380 三叉戟
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T312380?contestId=109938
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-12 13:56:19 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

int n, s;

struct Node
{
	int i, l, m, r;
	Node(int i = 0, int l = '*', int m = '*', int r = '*'):
		i(i), l(l), m(m), r(r) {}
};

Node t[210];
int cnt[210];
vector<int> faq;

inline void yxx(int rt)
{
	putchar(t[rt].i);
	if (t[rt].l != '*') yxx(t[rt].l);
	if (t[rt].m != '*') yxx(t[rt].m);
	if (t[rt].r != '*') yxx(t[rt].r);
}
inline void yqx(int rt)
{
	if (t[rt].r != '*') yqx(t[rt].r);
	if (t[rt].l != '*') yqx(t[rt].l);
	putchar(t[rt].i);
	if (t[rt].m != '*') yqx(t[rt].m);
}
inline void dzx(int rt)
{
	if (t[rt].m != '*') dzx(t[rt].m);
	putchar(t[rt].i);
	if (t[rt].r != '*') dzx(t[rt].r);
	if (t[rt].l != '*') dzx(t[rt].l);
}

int main()
{
	cin >> n; char x, l, r, m;
	while (cin >> x >> l >> m >> r)
	{
		faq.pb(x);
		++cnt[l]; ++cnt[r]; ++cnt[m];
		if (t[l].i == 0) t[l] = Node(l);
		if (t[m].i == 0) t[m] = Node(m);
		if (t[r].i == 0) t[r] = Node(r);
		t[x] = Node(x, l, m, r);
	}
	for (auto x : faq)
		if (cnt[x] == 0) { s = x; break; }
	
	yxx(s); putchar('\n');
	dzx(s); putchar('\n');
	yqx(s); putchar('\n');
	return 0;
}