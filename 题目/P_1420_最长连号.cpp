#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, cnt = 1, ans = -1145141919;
int a[100010];

int main()
{
    scanf("%d", &n); a[0] = -114514;
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] - a[i - 1] == 1)
            ++cnt;
        else
            cnt = 1;
        ans = max(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}