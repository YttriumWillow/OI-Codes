#include <iostream>

#include <cstring>
#include <bitset>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

string s1, s2, opt, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> s1 >> s2;
	// reverse(s1.begin(), s1.end());
	// reverse(s2.begin(), s2.end());
	bitset<10> a(s1);
	bitset<10> b(s2);
	cout << a << endl;
	cout << b << endl;
	cin >> opt;
	if (opt == "or")  ans = (a | b).to_string();
	if (opt == "and") ans = (a & b).to_string();
	if (opt == "xor") ans = (a ^ b).to_string();
	
	// reverse(ans.begin(), ans.end());
	
	for (reg int i = 0, flag = 0; i < ans.size(); ++i)
	{
		if (ans[i] != 0) flag = 1;
		if (flag) cout << ans[i];
	}
	cout << endl;
	
	cout << ans << endl;
			
	return 0;
}