#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint n, m, top;
longint a[50000010];
longint rt[50000010];

inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}

struct Node
{
    int l, r;
    longint val;
} t[50000010];

int clone(int now)
{
    top++;
    t[top] = t[now];
    return top;
}

int build(longint now, int l, int r)
{
    now = ++top;
    if (l == r)
    {
        t[now].val = a[l];
        return top;
    }
    longint mid = (l + r) >> 1;
    t[now].l = build(t[now].l, l, mid);
    t[now].r = build(t[now].r, mid + 1, r);
    return now;
}

int update(int now, int l, int r, longint x, longint val)
{
    now = clone(now);
    if (l == r)
        t[now].val = val;
    else
    {
        longint mid = (l + r) >> 1;
        if (x <= mid)
            t[now].l = update(t[now].l, l, mid, x, val);
        else
            t[now].r = update(t[now].r, mid + 1, r, x, val);
    }
    return now;
}

longint query(int now, int l, int r, longint x)
{
    if (l == r)
        return t[now].val;
    else
    {
        longint mid = (l + r) >> 1;
        if (x <= mid)
            return query(t[now].l, l, mid, x);
        else
            return query(t[now].r, mid + 1, r, x);
    }
}
int main()
{
    n = read(); m = read();
    for (reg int i = 1; i <= n; ++i)   
        a[i] = read();
    rt[0] = build(0, 1, n);
    for (reg int i = 1, ver, opr, x; i <= m; ++i)
    {
        longint y;
        ver = read(), opr = read(), x = read();
        if (opr == 1)
        {
            y = read();
            rt[i] = update(rt[ver], 1, n, x, y);
        }
        else
        {
            printf("%lld\n", query(rt[ver], 1, n, x));
            rt[i] = rt[ver];
        }
    }
    return 0;
}