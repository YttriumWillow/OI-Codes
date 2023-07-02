#include <iostream>

#define longing long long
#define reg register
#define qwq puts("fzy qwq~");

using namespace std;

int n;
int x, y, a, b;


int main()
{
    cin >> n;
    scanf("%d%d", &x, &y);
    scanf("%d%d", &a, &b);
    if (x < y)
        if (a < b)
            printf("%d %d\n", y, 0);
        else
            printf("%d %d\n", 0, y);
    else
        if (a < b)
            printf("%d %d\n", x, 0);
        else
            printf("%d %d\n", 0, x);
    return 0;
}