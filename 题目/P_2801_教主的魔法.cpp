#include <iostream>

#include <cmath>
#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, q, block;
// int L[1010], R[1010];
int tag[1010];
int a[1000010], d[1000010], bel[1000010];

template<typename _Tp>inline void read(_Tp &x)
{
	x = 0; char c = getchar(); bool f = 0;
	while (!isdigit(c)) f |= c == '-',  c = getchar();
	while (isdigit(c))  x = x * 10 + (c ^ 48),  c = getchar();
	return (void)(f ? x = -x : 1);
}

inline void build(int n)
{
    block = (int)sqrt(n);                    // 块的大小

    for (reg int i = 1; i <= n; ++i)    // 标记元素所属的块
        bel[i] = (i - 1) / block + 1;   // , d[i] = a[i];

    // for (reg int i = 1; i <= tot; ++i)  // 每个块的左右界
    // {
    //     L[i] = (i - 1) * block + 1;
    //     R[i] = i * block;
    // } R[tot] = n;

    // for (reg int i = 1; i <= tot; ++i)
    //     sort(d + L[i], d + R[i] + 1);
}

inline void add(int l, int r, int w)
{
    int L = bel[l];
    int R = bel[r];
    if (L == R)
    {
        for (reg int i = l; i <= r; ++i)
            a[i] += w;
        return;
    }
    for (reg int i = l; bel[i] <= L; ++i)
        a[i] += w;
    for (reg int i = L + 1; i < R; ++i)
        tag[i] += w;
    for (reg int i = r; bel[i] == R; --i)
        a[i] += w;
}

inline int query(int l, int r, int c)
{
    reg int res = 0, i = l;
    for (; i + 4 <= r; i += 4)
        res += (a[i] + tag[bel[i]]) >= c,
        res += (a[i + 1] + tag[bel[i + 1]]) >= c,
        res += (a[i + 2] + tag[bel[i + 2]]) >= c,
        res += (a[i + 3] + tag[bel[i + 3]]) >= c;
    for (; i <= r; ++i)
        res += (a[i] + tag[bel[i]]) >= c;
    return res;
}

int main()
{
    read(n), read(q);
    for (reg int i = 1; i <= n; ++i)
        read(a[i]);

    reg int l, r, x;
    build(n);

    while (q--)
    {
        char opr = getchar();
        while (opr != 'M' && opr != 'A')
			opr = getchar();
        read(l), read(r), read(x);
        if (opr == 'M') add(l, r, x);
        else printf("%d\n", query(l, r, x));
    }
    return 0;
}