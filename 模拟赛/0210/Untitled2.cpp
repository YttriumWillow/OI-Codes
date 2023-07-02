#include <iostream>

#include <vector>
#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define push push_back
#define pop pop_back
#define top back

using namespace std;

vector<int> st;
string str;
char ans[110];

int main()
{
	while (cin >> str)
	{
		st.clear();
		for (reg int i = 1; i <= 101; ++i)
			ans[i] = ' ';
		int len = str.size();
		for (reg int i = 0; i < len; ++i)
		{
			if (str[i] == '(')
			{
				st.push(i);
			}
			else if (str[i] == ')')
			{
				if (!st.empty())
					st.pop();
				else
					ans[i] = '?';
			}
		}
		for (auto x : st)
			ans[x] = '$';
		cout << str << endl;
		for (reg int i = 0; i < len; i++)
			cout << ans[i];
		cout << endl;
	}
	return 0;
}
