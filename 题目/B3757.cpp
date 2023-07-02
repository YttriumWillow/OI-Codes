// Problem:      B3757 [信息与未来 2021] 摩尔斯电码
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/B3757
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-29 09:51:56 

#include <iostream>

#include <map>
#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int T;
string str;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	map<string, char> faq;
	faq[".-"] = 'A';
	faq["-..."] = 'B';
	faq["-.-."] = 'C';
	faq["-.."] = 'D';
	faq["."] = 'E';
	faq["..-."] = 'F';
	faq["--."] = 'G';
	faq["...."] = 'H';
	faq[".."] = 'I';
	faq[".---"] = 'J';
	faq["-.-"] = 'K';
	faq[".-.."] = 'L';
	faq["--"] = 'M';
	faq["-."] = 'N';
	faq["---"] = 'O';
	faq[".--."] = 'P';
	faq["--.-"] = 'Q';
	faq[".-."] = 'R';
	faq["..."] = 'S';
	faq["-"] = 'T';
	faq["..-"] = 'U';
	faq["...-"] = 'V';
	faq[".--"] = 'W';
	faq["-..-"] = 'X';
	faq["-.--"] = 'Y';
	faq["--.."] = 'Z';
	while (T--)
	{
		cin >> str;
		cout << faq[str];
	}
	return 0;
}