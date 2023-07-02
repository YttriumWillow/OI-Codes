// Problem:      P7913 [CSP-S 2021] 廊桥分配
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P7913
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-24 20:21:05

#include <iostream>

#include <set>
#include <queue>
#include <algorithm>
#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;
namespace bufIO
{
    const int _Pu = 1 << 16;
    const int _d = 32;
    char buf[_Pu], obuf[_Pu];
    char *inl = buf + _Pu, *inr = buf + _Pu;
    char *outl = obuf, *outr = obuf + _Pu - _d;
    inline void flushin()
    {
        memmove(buf, inl, inr - inl);
        int rlen = fread(buf + (inr - inl), 1, inl - buf, stdin);
        if (inl - rlen > buf) { buf[inr - inl + rlen] = EOF; }
        inl = buf;
    }
    inline void flushout() { fwrite(obuf, outl - obuf, 1, stdout), outl = obuf; }
    template <typename _Tp>
    inline void read(_Tp &x)
    {
        if (inl + _d > inr) { flushin(); }
        int isne = 0;
        for (; !isdigit(*inl); ++inl) { isne = (*inl == '-'); }
        x = (*inl++ - '0');
        for (; isdigit(*inl); ++inl) { x = x * 10 + (*inl - '0'); }
        if (isne) { x = -x; }
    }
    template <typename _Tp>
    inline void writeln(_Tp x, char end = '\n')
    {
        if (outl > outr) { flushout(); }
        if (x < 0) { *outl++ = '-'; x = -x; }
        char sta[20]; char *top = sta;
        do { *top++ = (x % 10) + '0'; x /= 10; } while (x);
        do { *outl++ = *--top; } while (top != sta);
        (*outl++) = end;
    }
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
}
using namespace bufIO;

struct Flight
{
    int l, r;
    inline friend bool operator < (const Flight& _x, const Flight& _y)
    { return _x.l < _y.l; }
};
struct Arrival
{
    int r, alloc;
    inline friend bool operator < (const Arrival& _x, const Arrival& _y)
    { return _x.r > _y.r; }
};

int n, m1, m2, ans;
Arrival nw;
Flight f1[100010];
Flight f2[100010];
priority_queue<Arrival> q;
priority_queue<int, vector<int>, greater<int>> fr;
int cnt1[100010];
int cnt2[100010];

int main()
{
    read(n, m1, m2);
    for (reg int i = 1; i <= m1; ++i)
        read(f1[i].l, f1[i].r);
    for (reg int i = 1; i <= m2; ++i)
        read(f2[i].l, f2[i].r);
    sort(f1 + 1, f1 + m1 + 1);
    sort(f2 + 1, f2 + m2 + 1);

    for (reg int i = 1; i <= m1; ++i) fr.push(i);
    for (reg int i = 1; i <= m1; ++i)
    {
        while (!q.empty() && q.top().r < f1[i].l)
        	fr.push(q.top().alloc), q.pop();
        nw = { f1[i].r, fr.top() }, fr.pop();
        q.push(nw), ++cnt1[nw.alloc];
    }
    while (!fr.empty()) fr.pop();
    while (!q.empty()) q.pop();
    for (reg int i = 1; i <= m2; ++i) fr.push(i);
    for (reg int i = 1; i <= m2; ++i)
    {
        while (!q.empty() && q.top().r < f2[i].l)
            fr.push(q.top().alloc), q.pop();
        nw = { f2[i].r, fr.top() }, fr.pop();
        q.push(nw), ++cnt2[nw.alloc];
    }
    for (reg int i = 1; i <= n; ++i)
        cnt1[i] = cnt1[i - 1] + cnt1[i];
    for (reg int i = 1; i <= n; ++i)
        cnt2[i] = cnt2[i - 1] + cnt2[i];
    for (reg int i = 0; i <= n; ++i)
        ans = max(ans, cnt1[i] + cnt2[n - i]);

    writeln(ans);
    flushout();
    return 0;
}