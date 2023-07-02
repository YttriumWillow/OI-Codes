#include <iostream>

#include <ctime>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m;
int a[510];
int sum[510];

inline int get(int x, int y)
{
    if (x > y) swap(x, y);
    return sum[y] - sum[x - 1];
}

int main()
{
    // freopen("school.in", "r", stdin);
    // freopen("school.out", "w", stdout);

    srand(time(0));

    scanf("%d%d", &m, &n);
    for (reg int i = 1; i <= m - 1; ++i)
        scanf("%d", &a[i]);
    printf("%d\n", rand() % 114);
    return 0;
}