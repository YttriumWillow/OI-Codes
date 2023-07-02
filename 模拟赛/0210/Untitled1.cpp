#include <iostream>

#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

string str1, str2;
int a[210], b[210];
int ans[210], e;

int main() 
{
	cin >> str1;
	cin >> str2;
	int lena = str1.size();
	int lenb = str2.size();
	int limit = max(lena, lenb);
	for (reg int i = 0; i < lena; ++i)
		a[lena - i - 1] = str1[i] - '0';
	for (reg int i = 0; i < lenb; ++i)
		b[lenb - i - 1] = str2[i] - '0';
	for (reg int i = 0; i <= limit; ++i)
	{
		ans[i] += ( a[i] + b[i] );
		ans[i + 1] += ans[i] / 10 ;
		ans[i] %= 10;
	}
	for (reg int i = limit + 1; i >= 0; --i)
		if (ans[i] != 0)
		{
			e = i;
			break;
		}
//	cout << e << endl;
	for (reg int i = e; i >= 0; --i)
		cout << ans[i];
	return 0;
}
