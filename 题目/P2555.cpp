#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

#include <sstream>
namespace StringTookit
{
	stringstream ss;
	inline string getsubstr(string s, int l, int r) // position start from 0
	{
		r = min(r, (int)s.size());
		return s.substr(l, r - l + 1);
	}
	inline i64 cvttoint(string s)
	{
		i64 res = 0, sgn = 1;
		for (auto x : s)
		{
			if (x == '-') sgn = -1;
			if (isdigit(x)) res = res * 10 + (x ^ 48);
		}
		return res * sgn;
	}
	inline string cvttostring(i64 x)
	{
		string res = "";
		ss << x; ss >> res;
		ss.clear(); return res;
	}
} using namespace StringTookit;

namespace Read
{
	inline string makepart(i64 x)
	{
		if (x == 0) return "";
		string res = "";
		int g = x % 10;
		int s = x / 10 % 10;
		int b = x / 100 % 10;
		int q = x / 1000 % 10;
		cerr << q << ' ' << b << ' ' << s << ' ' << g << endl;
		if (q != 0) { res += char(q + '0'); res += 'Q'; }
		if (b != 0) { res += char(b + '0'); res += 'B'; }
		if (s != 0) { res += char(s + '0'); res += 'S'; }
		if (g != 0) { res += char(g + '0'); }
		return res;
	}
	char ord[4] = { 'q', '?', 'W', 'Y' };
	inline string readint(string s)
	{
		int n = s.size();
		i64 base = cvttoint(s);
		i64 part = 0, o = 1;
		string res = "";
		while (base)
		{
			part = base % 10000;
			base /= 10000;
			if (o != 1)
				res = ord[o] + res;
			++o;
			res = makepart(part) + res;
		}
		return res;
	}
} using namespace Read;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string s = "191274399021";
	cout << cvttoint(s) << endl;
	cout << readint(s) << endl;
	return 0;
}