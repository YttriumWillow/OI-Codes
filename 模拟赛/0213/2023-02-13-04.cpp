#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint l, n, m, ans = 0xffffffffff;

longint a[50010];

bool check(longint now)
{
    // printf("now:%lld mv:", now);

    int cnt = 0;
    for (reg int i = 0; i <= n + 1; ++i)
    {
        reg int j = i;
        while (j <= n + 1 && a[j] - a[i] <= now)
            ++j;
        cnt += j - i - 1;
        // printf("%d-%d ", i, j);
        i = j;
    }
    // printf("%d\n", cnt);
    return cnt <= m;
}

int main()
{
    freopen("house.in", "r", stdin);
    freopen("house.out", "w", stdout);

    scanf("%lld%lld%lld", &l, &n, &m);

    for (reg int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    a[n + 1] = l;

    reg longint l = 1, r = 1000000010;
    while (l < r)
    {
        longint mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1, ans = min(ans, mid);
        else
            r = mid;
    }

    // for (reg int i = 0; i <= n + 1; ++i)
    //     printf("%lld ", a[i]);
    // printf("\n");

    printf("%lld\n", ans);
    return 0;
}

//  && a[i + 1] - a[i - 1] >= now