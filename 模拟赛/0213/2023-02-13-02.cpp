#include <iostream>

#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

struct Seg
{
    int l, r;
    // int length;
    Seg() {}
    Seg(int _l, int _r): l(_l), r(_r) {}
    friend bool operator < (Seg _x, Seg _y)
    {
        if (_x.r != _y.r)
            return _x.r < _y.r;
        else
            return _x.l <_y.l;
    }
} a[1010];

int n, len, now, ans;

int main()
{
    // freopen("choice.in",  "r", stdin );
    // freopen("choice.out", "w", stdout);

    scanf("%d", &n);

    for (reg int i = 1, l, r; i <= n; ++i)
    {
        scanf("%d%d", &l, &r);
        a[i] = Seg(l, r);
        len = max(len, r);
    }

    sort(a + 1, a + n + 1);

    for (reg int i = 1; i <= n; ++i)
    {
        if (a[i].l > now)
        {
            now = a[i].r;
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}