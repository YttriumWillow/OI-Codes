#include <iostream>

#include <cstring>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int base = 131;

int n, pos;
u64 now = 1;
u64 pre;
u64 suf;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> str)
    {
        n = str.size(); pos = 0;
        pre = suf = 0; now = 1;
        
        for (reg int i = n - 1; i >= 0; --i)
        {
            pre = pre * base + str[i];
            suf = suf + str[i] * now;
            now *= base;
            if (pre == suf)
                pos = i;
        }
        cout << str;
        for (reg int i = pos - 1; i >= 0; --i)
            cout << str[i];
        cout << endl;
    }
    // while (cin >> s)
    // {
    // int Len = s.size(), pos = 0;
    // int num = 1, pre[100010] = {0}, lst[100010] = {0};
    // for (int i = Len - 1; i >= 0; i--)
    // {
    // pre[i] = pre[i + 1] * base + s[i], lst = lst[i + 1] + s[i] * num, num *= base;
    // if (pre == lst)
    // pos = i;
    // }
    // cout << s;
    // for (int i = wz - 1; i >= 0; i--)
    // cout << s[i];
    // cout << endl;
    // }
    return 0;
}