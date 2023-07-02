#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define reg register
#define uint unsigned int
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define getchar() (ipos == iend and (iend = (ipos = _ibuf) + fread(_ibuf, 1, __bufsize, stdin), ipos == iend) ? EOF : *ipos++)
#define putchar(ch) (opos == oend ? fwrite(_obuf, 1, __bufsize, stdout), opos = _obuf : 0, *opos++ = (ch))
#define __bufsize (1 << 20)

using namespace std;

char _ibuf[__bufsize], _obuf[__bufsize], _stk[20];
char *ipos = _ibuf, *iend = _ibuf, *opos = _obuf, *oend = _obuf + __bufsize, *stkpos = _stk;

struct END { ~END() { fwrite(_obuf, 1, opos - _obuf, stdout); } } __;

inline int read()
{
    reg int x = 0; reg char ch;
    while (!isdigit(ch = getchar()));
    while (x = (x << 3) + (x << 1) + (ch & 15), isdigit(ch = getchar()));
    return x;
}

template <typename _INT>
inline void write(_INT x)
{
    while (*++stkpos = x % 10 ^ 48, x /= 10, x);
    while (stkpos != _stk)
        putchar(*stkpos--);
}

inline void read(char* str)
{
    while (isspace(*str = getchar()));
    while (!isspace(*++str = getchar()));
    *str = '\0';
}

int t, cur, n; char opt[7];
vector<char> editor, line;

int main()
{
    t = read();
    while (t--)
    {
        read(opt);
        switch (opt[0])
        {
        case 'M' :
            cur = read(); break;
        case 'I' :
            line.clear(), line.resize(read());
            for (reg uint i = 0; i < line.size(); ++i)
                line[i] = getchar();
            editor.insert(editor.begin() + cur, line.begin(), line.end());
            break;
        case 'D' : editor.erase(editor.begin() + cur, editor.begin() + cur + read()); break;
        case 'G' :
            putchar(editor[cur]);
            if (editor[cur] != '\n') putchar('\n');
            break;
        case 'P' : --cur; break;
        case 'N' : ++cur; break;
        case 'R' : reverse(editor.begin() + cur, editor.begin() + cur + read()); break;
        // default : qwq
        }
    }
    return 0;
}
