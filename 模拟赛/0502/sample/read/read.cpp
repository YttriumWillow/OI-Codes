#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

string str;
bool flagpoint, flagzero, flagneg, flagline;
int pospoint, posline, posneg, poszero;

namespace Read
{
	char wtm[4] = { '?', '*', 'W', 'Y' };
	inline bool check(string s)
	{
		int tmp = 0;
		for (reg int i = 0; i <= pospoint; ++i)
			tmp += ('1' <= s[i] && s[i] <= '9');
		return tmp == 0;
	}
	inline void cheat(string s)
	{
		if (s[0] == '-') cout << 'F';
		cout << "0D";
		int ed = s.size() - 1;
		while (s[ed] == '0') --ed; 
		for (reg int i = pospoint + 1; i <= ed; ++i)
			cout << str[i];
	}
	inline void cheat2() { cout << 0 << endl; }
	inline int readN(string s, int l)
	{
		bool falg
		while (s[l] == '-')
		{
			flag ^= 1;
		}
		return l;
	}
	char op[4] = { '&', 'S', 'B', 'Q' };
	inline string make(int x)
	{
		string res; int u = 0; bool flg = 0;
		while (x)
		{
			char p = (x % 10) + '0';
			if (p != '0') flg = true;
			if (u >= 1 && p != '0')
			{
				res = op[u] + res;
			}
			++u;
			if (!flg && p == '0') {}
			else res = p + res;	
			x /= 10;
		}
		// if (x / 1000 == 0) res = '0' + res; // !!!!!!!!
		return res;
	}
	inline int readZ(string s, int l, int r) // 读出依托整数
	{
		l = readN(s, l);
		string t = s.substr(l, (r - l) + 1);
		// cerr << t << endl;
		
		i64 now = 0, faq = 0;
		for (auto x : t)
			now = now * 10 + (x - '0');
		// cerr << now << endl;
		
		string shht = "";
		for (reg int i = 1; i <= 3 && now; ++i)
		{
			faq = now % 10000;
			now /= 10000;
			// cout << faq;
			string blk = "";
			if (faq != 0) blk = blk + make(faq);
			if (faq != 0 && i != 1) blk += wtm[i];
			if (now && faq / 1000 == 0 && faq != 0) blk = '0' + blk; 
			shht = blk + shht;
		}
		cout << shht;
			
		return 0;
	}
	inline string readZZ(string s, int l, int r) // 读出依托整数
	{
		l = readN(s, l);
		string t = s.substr(l, (r - l) + 1);
		// cerr << t << endl;
		
		i64 now = 0, faq = 0;
		for (auto x : t)
			now = now * 10 + (x - '0');
		// cerr << now << endl;
		
		string shht = "";
		for (reg int i = 1; i <= 3 && now; ++i)
		{
			faq = now % 10000;
			now /= 10000;
			// cout << faq;
			string blk = "";
			if (faq != 0) blk = blk + make(faq);
			if (faq != 0 && i != 1) blk += wtm[i];
			if (now && faq / 1000 == 0 && faq != 0) blk = '0' + blk; 
			shht = blk + shht;
		}
		return shht;
	}
	inline int cuttail(string s, int r)
	{
		while (s[r] == '0') --r;
		return r;
	}
	inline void readP(string s, int l, int r)
	{
		l = readN(s, l);
		// r = cuttail(s, r);
		int posD = 0;
		for (reg int i = l; i <= r; ++i)
			if (s[i] == 'D')
				posD = i;
		string tmp = readZZ(s, l, posD - 1);
		string t = s.substr(posD + 1, (r - posD));
		bool flg2 = 0;
		for (auto x: t)
			if (x != '0')
				flg2 = 1;
		cout << tmp;
		if (tmp.size() == 0) cout << '0';
		if (flg2) cout << 'D' << t; 
	}
	inline void readF(string s, int l, int r)
	{
		i64 u = 0, d = 0; int cntline = 0;
		bool fu = 0, fd = 0;
		bool nu = 0, nd = 0;
		for (reg int i = l; i < posline; ++i)
			if (isdigit(s[i]))
				u = u * 10 + (s[i] - '0');
		if (u == 0) { cout << 0 << endl; return; }
		for (reg int i = 0; i < posline; ++i)
		{
			if (s[i] == 'D') { fu = 1; }
			if (s[i] == '-') { nu = 1; ++cntline; }
		}
		for (reg int i = posline + 1; i <= r; ++i)
		{
			if (s[i] == 'D') { fd = 1; }
			if (s[i] == '-') { nd = 1; ++cntline; }
		}
		int st2 = posline + 1;
		if (nu && nd) ++l, ++st2;
		
		if (fd)
			readP(s, st2, r);
		else
			readZ(s, st2, r);
		cout << "fz";
		if (fu)
			readP(s, l, posline - 1);
		else
			readZ(s, l, posline - 1);
	}
}
using namespace Read;
int main()
{
	
	cin >> str;
	for (reg int i = 0; i < (i64)str.size(); ++i)
	{
		if (str[i] == '.') { flagpoint = 1; pospoint = i; }
		if (str[i] == '-') { flagneg = 1; posneg = i; }
		if (str[i] == '/') { flagline = 1; posline = i; }
		if (str[i] == '0') { flagzero = 1; poszero = i; }
	}
	if (flagpoint) for (auto &x : str) if (x == '.') x = 'D';
	if (flagpoint && flagzero && check(str) && !flagline) cheat(str);
	else if (!flagline && !flagpoint) readZ(str, 0, str.size() - 1);
	else if (flagpoint && !flagline) readP(str, 0, str.size() - 1);
	else readF(str, 0, str.size() - 1);
	// else cheat2();
	return 0;
}