#include <iostream>

#include <string>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, used[25], ans;
string str[25];
char start;

int match(string str1, string str2)
{
    int len1 = str1.size();
    int len = min(str1.size(), str2.size());
    for (int i = 1; i < len; ++i)
    {
        int flag = 1;
        for (int j = 0; j < i; ++j)
            if (str1[len1 - i + j] != str2[j])
                flag = 0;
        if (flag) return i;
    }
    return 0;
}

void dfs(string now, int len)
{
    ans = max(ans, len);
    for (reg int i = 1; i <= n; ++i)
    {
        if (used[i] >= 2)
            continue;
        int p = match(now, str[i]);
        if (p > 0)
        {
            used[i]++;
            dfs(str[i], len + str[i].size() - p);
            used[i]--;
        }
    }
}

int main()
{
    cin >> n;
    for (reg int i = 1; i <= n; ++i)
        cin >> str[i];
    cin >> start;
    for (reg int i = 1; i <= n; ++i)
    {
        if (str[i][0] == start)
        {
            used[i]++;
            dfs(' ' + str[i], str[i].size());
            used[i]--;
        }
    }
    cout << ans << endl;
	return 0;
}
