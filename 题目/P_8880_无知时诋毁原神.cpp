#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;
int a[100010];
int b[100010];
int c[100010];
int x[100010];
int ansa[100010];
int ansb[100010];

int main()
{
    scanf("%d", &n);
    if (!(n % 2)) { printf("-1\n"); return 0; }
    for (reg int i = 1; i <= n; ++i)
        scanf("%d", &c[i]);

    for (reg int i = 2; i <= n; ++i)
        a[i] = i - 1, b[i - 1] = i - 1;
    a[1] = 0; b[n] = 0;

    for (reg int i = 1; i <= n; ++i)
        x[(a[i] + b[i]) % n] = i;
    for (reg int i = 1; i <= n; ++i)
        ansa[i] = a[x[c[i]]],
        ansb[i] = b[x[c[i]]];
    
    for (reg int i = 1; i <= n; ++i)
        printf("%d ", ansa[i]);
    printf("\n");
    for (reg int i = 1; i <= n; ++i)
        printf("%d ", ansb[i]);
    return 0;
}