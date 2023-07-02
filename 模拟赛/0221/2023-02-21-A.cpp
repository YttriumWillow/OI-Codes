#include <iostream>

#include <cstring>
#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const string table = "0123456789ABCDEFG";

int n;
string m, now;
// char nc[1000010];

int toInt(char x) { if (isdigit(x)) return x - '0'; else return x - 'A' + 10; }

char toChar(int x) { return table[x]; }


bool check(string x)
{
    string s = x;
    reverse(s.begin(), s.end());
    return s == x;
}

inline string add(string b)
{
	string a = b;
	reverse(b.begin(), b.end());
	string res = "";
	int len = a.size();
	int jw = 0, bw = 0;
	for (reg int i = 0; i < len; ++i)
	{
		bw = toInt(a[i]) + toInt(b[i]) + jw;
		// cout << toChar(bw) << endl;
		jw = bw / n;
		bw %= n;
		res += toChar(bw);
		// cout << res << endl;
	}
	if (jw != 0)
		res += toChar(jw);
	return res;
}

int main()
{
	// freopen("moslems.in", "r", stdin);
	// freopen("moslems.out", "w", stdout);
	
	cin >> n;
	cin >> m; now = m;
	for (reg int i = 1; i <= 40; ++i)
	{
		if ( check(now) )
		{
			cout << i - 1 << endl;
			return 0;
		}
		// cout << now << endl;
		now = add(now);
	}
	cout << "Impossible" << endl;
	return 0;
}