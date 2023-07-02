#include <iostream>

#include <algorithm>
#include <vector>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

using namespace std;

struct Node
{
    int x, y;
    friend bool operator<(Node _a, Node _b)
    {
        if (_a.x != _a.y)
            return _a.x > _b.x;
        else
            return _a.y > _b.y;
    }
} a[110];

vector<Node> ans;

bool cmp(Node _a, Node _b)
{
    return _a.x < _b.x;
}

int n;

int main()
{
    // freopen("maxbot.in", "r", stdin);
    // freopen("maxbot.out", "w", stdout);

    scanf("%d", &n);
    for (reg int i = 1, x, y; i <= n; ++i)
    {
        scanf("%d%d", &x, &y);
        a[i].x = x;
        a[i].y = y;
    }

    sort(a + 1, a + n + 1);

    bool flag;
    for (reg int i = 1; i <= n; ++i)
    {
        flag = true;
        for (reg int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            if (a[i].x <= a[j].x && a[i].y <= a[j].y)
                flag = false;
        }
        if (flag)
        {
            ans.pb(a[i]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("(%d,%d)", ans[0].x, ans[0].y);
    int l = ans.size();
    for (reg int i = 1; i < l; ++i)
        printf(",(%d,%d)", ans[i].x, ans[i].y);

    return 0;
}