#include <iostream>

#include <algorithm>
#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int t[201], n;
char x;
string str;

struct Node
{
	string str;
	friend bool operator < (const Node &_x, const Node &_y)
	{
		int lmt = min(_x.str.size(), _y.str.size());
        for (reg int i = 0; i < lmt; ++i)
        {
            if (t[_x.str[i]] == t[_y.str[i]]) continue;
            else 	return t[_x.str[i]] < t[_y.str[i]];
        }
        return _x.str.size() < _y.str.size();
    }
} s[1010];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (reg int i = 1; i <= 26; ++i)
		cin >> x, t[x] = i;
	for (reg int i = 1; i <= n; ++i)
	{
		cin >> str;
		s[i] = { str };
	}
	sort(s + 1, s + n + 1);
	for (reg int i = 1; i <= n; ++i)
		cout << s[i].str << endl;
	return 0;
}