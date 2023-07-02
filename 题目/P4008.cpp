// Problem:      P4008 [NOI2003] 文本编辑器
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4008
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-20 18:55:04

#include <iostream>

#include <ext/rope>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;
using namespace __gnu_cxx;

int t, n, k;
string opt;
string s, line;
crope editor;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> opt;
        switch (opt[0])
        {
        case 'M': cin >> k; break;
        case 'I':
        	cin >> n; s = line = "";
            cin.ignore(256, '\n');
            while (n)
            {
                getline(cin, line);
                while (line.back() < 32 || line.back() > 126)
                    line.pop_back();
                s += line; n -= line.size();
            }
            editor.insert(k, s.c_str()); break;
        case 'D': cin >> n, editor.erase(k, n); break;
        case 'G': cin >> n, cout << editor.substr(k, n) << endl; break;
        case 'P': --k; break;
        case 'N': ++k; break;
        default: qwq
	   	}
    }
    return 0;
}