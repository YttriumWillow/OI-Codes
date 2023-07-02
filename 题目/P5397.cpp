// Problem:      P5397 [Ynoi2018] 天降之物
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5397
// Memory Limit: 256 MB
// Time Limit:   500000 ms
// Created Time: 2023-07-01 17:51:00

#include <iostream>

#include <cstring>
#include <algorithm>

#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx512f,sse4.1,sse4.2,avx2,popcnt")

using namespace std;
#include <cstring>
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

inline void print(int x)
{
    if (x < 0) putchar('-'), x *= -1;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

const int M = 385, N = 100005, B = N / M + 6;

int len, n, m, cnt;
int op, x, y, ans;
int cntt[B], pos[N][B], l[B], r[B];
int fir[M][B];
int lst[M][B], dis[B][M][M];

struct node { int rnk, x, id; } a[N];
inline bool cmp1(node a, node b) { return a.x < b.x; }
inline bool cmp2(node a, node b) { return a.id < b.id; }

inline void init()
{
    len = M - 5;
    cnt = n / len + !!(n % len);
    for (int i = 1, j = 1; i <= n; i += len, ++j)
        l[j] = r[j - 1] + 1,
        r[j] = i + len;
    r[cnt] = min(n, r[cnt]);
    for (int i = 1; i <= cnt; ++i)
    {
        sort(a + l[i], a + r[i] + 1, cmp1);
        a[l[i]].rnk = 1;
        pos[a[l[i]].x][i] = a[l[i]].rnk;
        for (int j = l[i] + 1; j <= r[i]; ++j)
        {
            if (a[j].x != a[j - 1].x)
                a[j].rnk = a[j - 1].rnk + 1;
            else
                a[j].rnk = a[j - 1].rnk;
            pos[a[j].x][i] = a[j].rnk;
        }
        cntt[i] = a[r[i]].rnk;
        sort(a + l[i], a + r[i] + 1, cmp2);
    }
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= cnt; ++i)
    {
        for (int j = l[i]; j <= r[i]; ++j)
            if (!fir[a[j].rnk][i])
                fir[a[j].rnk][i] = j;
        for (int j = r[i]; j >= l[i]; --j)
            if (!lst[a[j].rnk][i])
                lst[a[j].rnk][i] = j;
        for (int j = l[i]; j <= r[i]; ++j)
            for (int k = j + 1; k <= r[i]; ++k)
            {
                int minn = min(a[j].rnk, a[k].rnk), maxn = max(a[j].rnk, a[k].rnk);
                dis[i][minn][maxn] = min(dis[i][minn][maxn], k - j);
            }
    }
}
inline void update(int x, int y)
{
    for (int i = 1; i <= cnt; ++i)
    {
        if (!pos[x][i]) continue;
        else if (!pos[y][i])
            pos[y][i] = pos[x][i], pos[x][i] = 0;
        else
        {
            int posx = pos[x][i], posy = pos[y][i];
            if (posx > posy)
            {
                for (int j = 1; j <= posy; ++j)
                    dis[i][j][posy] = min(dis[i][j][posy], dis[i][j][posx]);
                for (int j = posy + 1; j <= posx; ++j)
                    dis[i][posy][j] = min(dis[i][posy][j], dis[i][j][posx]);
                for (int j = posx + 1; j <= cntt[i]; ++j)
                    dis[i][posy][j] = min(dis[i][posy][j], dis[i][posx][j]);
            }
            else
            {
                for (int j = 1; j <= posx; ++j)
                    dis[i][j][posy] = min(dis[i][j][posy], dis[i][j][posx]);
                for (int j = posx + 1; j <= posy; ++j)
                    dis[i][j][posy] = min(dis[i][j][posy], dis[i][posx][j]);
                for (int j = posy + 1; j <= cntt[i]; ++j)
                    dis[i][posy][j] = min(dis[i][posy][j], dis[i][posx][j]);
            }
            fir[posy][i] = min(fir[posx][i], fir[posy][i]);
            lst[posy][i] = max(lst[posx][i], lst[posy][i]);
            fir[posx][i] = lst[posx][i] = pos[x][i] = 0;
        }
    }
}
inline int getans(int x, int y)
{
    int ans = dis[0][0][0], ex, ey, nx = -1e9, ny = -1e9;
    if (x == y)
    {
        for (int i = 1; i <= cnt; ++i)
            if (pos[x][i]) return 0;
        return -1;
    }
    for (int i = 1; i <= cnt; ++i)
        ans = min(ans, 
        dis[i][min(pos[x][i], pos[y][i])][max(pos[x][i], pos[y][i])]);
    for (int i = 1; i <= cnt; ++i)
    {
        if (ex = fir[pos[x][i]][i])
            ans = min(ans, ex - ny);
        if (ey = fir[pos[y][i]][i])
            ans = min(ans, ey - nx);
        ex ? (nx = lst[pos[x][i]][i]) : 0;
        ey ? (ny = lst[pos[y][i]][i]) : 0;
    }
    return ans >= n ? -1 : ans;
}
int main()
{
    read(n, m);
    for (int i = 1; i <= n; ++i)
        read(a[i].x), a[i].id = i;
    init();
    for (int i = 1; i <= m; ++i)
    {
        read(op), read(x), read(y);
        x ^= ans, y ^= ans;
        if (op == 1)
            x != y ? update(x, y) : (void)0;
        else
        {
            ans = getans(x, y);
            ans == -1 ? (puts("Ikaros"), ans = 0) : (printf("%d\n", ans));
        }
    }
    return 0;
}