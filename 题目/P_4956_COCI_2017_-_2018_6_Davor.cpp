#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;

int main()
{
    scanf("%d", &n); n /= 364;
    if (n <= 103)
        printf("%d\n%d\n", n - 3, 1);
    else
    {
        if (n % 3 == 0) printf("%d\n%d\n", 99, (n - 99) / 3);//分类讨论，直接输出
        if (n % 3 == 1) printf("%d\n%d\n", 100, (n - 100) / 3);
        if (n % 3 == 2) printf("%d\n%d\n", 98, (n - 98) / 3);
    }
    return 0;
}