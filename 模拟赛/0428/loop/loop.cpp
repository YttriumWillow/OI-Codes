#include <iostream>

#include <cstring>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, ans;
string s, t;
int fails[500010];
int failt[500010];

#include <iostream>

#include <cstring>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, ans;
string s, t;
int fails[500010];
int failt[500010];

inline void KMP(string s, int fail[])
{
	int n = s.size(); fail[0] = 0;
	for (reg int i = 1, j = 0; i <= n; ++i)
	{
		while (j != 0 && s[i] != s[j])
			j = fail[j - 1];
		if (s[i] == s[j])
			++j;
		fail[i] = j;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s; t = s; n = s.size();
	reverse(t.begin(), t.end());
	KMP(s, fails);
	KMP(t, failt);
	bool flag = 1;
	for (auto x : s)
		if (x != s[0])
			flag = 0;
	if (flag) { cout << n << endl << 1 << endl; return 0; }
	else if (fails[n - 1] == 0 || n % (n - fails[n - 1]) != 0)
	{ cout << 1 << endl << 1 << endl; return 0; }
	for (reg int i = 1; i <= n; ++i)
	{
		int j = n - i;
		if ( (fails[i - 1] == 0 || i % (i - fails[i - 1]) != 0)
		&&	 (failt[j - 1] == 0 || j % (j - failt[j - 1]) != 0) )
			++ans;	
	}
	cout << 2 << endl << ans << endl;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s; t = s; n = s.size();
	reverse(t.begin(), t.end());
	KMP(s, fails);
	KMP(t, failt);
	bool flag = 1;
	for (auto x : s)
		if (x != s[0])
			flag = 0;
	if (flag) { cout << n << endl << 1 << endl; return 0; }
	else if (fails[n - 1] == 0 || n % (n - fails[n - 1]) != 0)
	{ cout << 1 << endl << 1 << endl; return 0; }
	for (reg int i = 1; i <= n; ++i)
	{
		int j = n - i;
		if ( (fails[i - 1] == 0 || i % (i - fails[i - 1]) != 0)
		&&	 (failt[j - 1] == 0 || j % (j - failt[j - 1]) != 0) )
			++ans;	
	}
	cout << 2 << endl << ans << endl;
	return 0;
}