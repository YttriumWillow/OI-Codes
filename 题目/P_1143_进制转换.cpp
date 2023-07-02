#include <iostream>

#define longing long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, x;

inline int check(char c)
{
    if (c >= 'A' && c <= 'F')   return c - 55;
    if (c > 47 && c < 58)       return c - 48;
    return -1;
}
inline void read(int& x)
{
    x = 0;
    char ch = getchar();
    while (check(ch) == -1) ch = getchar();
    while (~check(ch))      x *= n, x += check(ch), 
                            ch = getchar();
}
inline char change(int x)
{
    if (x < 10) return x + '0';
    return x - 10 + 'A';
}
void write(int k)
{
    if (!k) return;
    write(k / m);
    putchar(change(k % m));
}
int main()
{
    cin >> n;
    read(x);
    cin >> m;
    write(x);
    return 0;
}