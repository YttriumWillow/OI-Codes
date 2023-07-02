#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq~");

using namespace std;

char s1[110][110];
char s2[110][110];
bool method[8];
int n;

/*
\ 1 2 3
1 @ - @
2 - - -
3 @ @ -

\ 1 2 3
1 @ - @
2 @ - -
3 - - @
*/

bool cmp1()
{
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n ++j)
            if (s1[i][j] != s2[n + 1 - j][i])
                return false;
    return true;
}
bool cmp2()
{
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n ++j)
            if (s1[i][j] != s2[n + 1 - i][n + 1 - j])
                return false;
    return true;
}
bool cmp3()
{
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n ++j)
            if (s1[i][j] != s2[n + 1 - j][i])
                return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n; ++j)
            scanf("%c", &s1[i][j]);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n; ++j)
            scanf("%c", &s2[i][j]);
    

    return 0;
}