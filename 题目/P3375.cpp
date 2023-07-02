// Problem:      P3375 【模板】KMP字符串匹配
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3375
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-02-28 20:05:32

#include <iostream>
#include <string>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

string txt, pat;
int n, m, nxt[1000010];

int main()
{
    cin >> txt >> pat;
    n = txt.size();
    m = pat.size();
    
    int j = 0;
    for (reg int i = 1; i < m; ++i)
    {
        while (j > 0 && pat[i] != pat[j])
            j = nxt[j - 1];
        if (pat[i] == pat[j])
            j++;
        nxt[i] = j;
    }
    
    j = 0;
    for (reg int i = 0; i < n; ++i)
    {
        while (j > 0 && txt[i] != pat[j])
            j = nxt[j - 1];
        if (txt[i] == pat[j])
            ++j;
        if (j == m)
        {
            cout << i - m + 2 << endl;
            j = nxt[j - 1];
        }
    }
    
    for (reg int i = 0; i < m; ++i)
    	cout << nxt[i] << ' ';
    return 0;
}