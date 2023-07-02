#include <iostream>

#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, ans = 0x3f3f3f3f;
struct Node 
{
    int val;
    int id;
    friend bool operator < (Node _x, Node _y) { return _x.val < _y.val; }
} a[100010];

// int dif[100010];

int main()
{
    scanf("%d%d", &n, &m);
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].val);
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    // for (reg int i = 1; i <= n; ++i)
    //     dif[i] = a[i].val - a[i - 1].val;
    for (reg int i = m; i <= n; ++i)
    {
        int x = a[i].val - a[i - (m - 1)].val;
        if (x < ans)
        {
            ans = x;
        }
    }
    printf("%d\n", ans);
    return 0;
}