#include <iostream>

#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

string stra, strb;
int a[510], b[510];
int ans[510];
int len;


int main()
{
    // freopen("mul.in",  "r", stdin );
    // freopen("mul.out", "w", stdout);

    cin >> stra >> strb;
    a[0] = stra.size();
    b[0] = strb.size();
    for (reg int i = 1; i <= a[0]; ++i)
        a[i] = stra[a[0] - i] - '0';
    for (reg int i = 1; i <= b[0]; ++i)
        b[i] = strb[b[0] - i] - '0';
    for (reg int i = 1; i <= a[0]; ++i)
        for (reg int j = 1; j <= b[0]; ++j)
            ans[i + j - 1] += a[i] * b[j];
    len = a[0] + b[0];
    for (reg int i = 1; i <= len; ++i)
    {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    for (reg int i = len; i >= 1; --i)
        if (ans[i] != 0)
        {
            len = i;
            break;
        }
    for (reg int i = len; i >= 1; --i)
        cout << ans[i];
    return 0;
}