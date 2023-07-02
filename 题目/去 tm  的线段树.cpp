// Problem:      P3372 【模板】线段树 1
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3372
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-24 14:28:02

#include <iostream>

#define i64 long long
#define qwq puts("fzy qwq ~");
#define ls(k) ((k) << 1)
#define rs(k) ((k) << 1 | 1)
#define nownode tree[now]
#define leftson tree[ls(now)]
#define rightson tree[rs(now)]

using namespace std;

i64 n, m;
i64 opt, x, y;
i64 a[200010], k;

struct Node
{
	i64 l, r;
	i64 val, tag;
	i64 siz() { return r - l + 1; }
} tree[400010];

void pushup(i64 now) { nownode.val = leftson.val + rightson.val; }

void pushdown(i64 now)
{
	if (nownode.tag)
	{
		leftson.val += nownode.tag * leftson.siz();
		rightson.val += nownode.tag * rightson.siz();
		leftson.tag += nownode.tag;
		rightson.tag += nownode.tag;
		nownode.tag = 0;
	}
}

void build(i64 l, i64 r, i64 now)
{
	nownode.l = l; nownode.r = r;
	if (l == r) { nownode.val = a[l]; return; cerr<<"faq\n";}
	i64 mid = (l + r) >> 1;
	build(l, mid, ls(now));
	build(mid + 1, r, rs(now));
	pushup(now);
}

void add(i64 l, i64 r, i64 now, i64 k)
{
	if (l <= nownode.l && nownode.r <= r)
	{
		nownode.val += k * nownode.siz();
		nownode.tag += k;
		return;
	}
	pushdown(now);
	i64 mid = (nownode.l + nownode.r) >> 1;
	if (x <= mid)     add(l, r, ls(now), k);
	if (y >= mid + 1) add(l, r, rs(now), k);
	pushup(now);
}

i64 query(i64 l, i64 r, i64 now)
{
	if (l <= nownode.l && nownode.r <= r)
		return nownode.val;
	pushdown(now);
	i64 mid = (nownode.l + nownode.r) >> 1;
	i64 ans = 0;
	if (l <= mid)
		ans += query(l, r, ls(now));
	if (mid + 1 <= r)
		ans += query(l, r, rs(now));
	return ans;
}

int main()
{
    read(n, m);
    readln(a, n);
	build(1, n, 1);
    while (m--)
    {
        read(opt, x, y);
        switch (opt)
        {
        case 1: read(k), add(x, y, 1, k); break;
        case 2: writeln(query(x, y, 1)); break;
        default: qwq
        }
    }
    return 0;
}