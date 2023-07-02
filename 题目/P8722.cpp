// Problem:	P8722 [蓝桥杯 2020 省 AB3] 日期识别
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P8722
// Memory Limit:	128 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-23 19:57:23

#include <iostream>

#include <cstring>
#include <map>
#include <sstream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define make make_pair

using namespace std;

map<string, int> m;
string date;
int day;

void init()
{
    m["Jan"] = 1;
    m["Feb"] = 2;
    m["Mar"] = 3;
    m["Apr"] = 4;
    m["May"] = 5;
    m["Jun"] = 6;
    m["Jul"] = 7;
    m["Aug"] = 8;
    m["Sep"] = 9;
    m["Oct"] = 10;
    m["Nov"] = 11;
    m["Dec"] = 12;
}

int main()
{
    init();

	string date;
    cin >> date;
    month = date.substr(0, 3);
	day = date.substr(3, 2);
	
	
    istringstream is(date.substr(3, 2));
    is >> day;
	string month = date.substr(0, 3);
	
    cout << m[month] << ' ' << day << endl;
    return 0;
}