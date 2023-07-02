// Problem:      T323941 不死「火鸟　−凤翼天翔−」
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T323941?contestId=105752
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-09 19:55:19 

#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int ax, ay, bx, by;
int dx, dy, ddx, ddy;

int main()
{
	cin >> ax >> ay >> bx >> by;
	dx = (ax - bx);
	dy = (ay - by);
	if ((dx & 1) == 0 && (dy & 1) == 0)
		{ cout << abs(dx) + abs(dy) << endl; return 0; }
	ddx = dx % 2;
	ddy = dy % 2;
	// cerr << ddx << ' ' << ddy << endl;
	// cerr << dx << ' ' << dy << endl;
	// cerr << (abs(ddx) & 1) << ' ' <<  (abs(ddy) & 1) << endl;
	if ( ( (abs(ddx) & 1) != (abs(ddy) & 1) ) )
		{ cout << -1 << endl; return 0; }
	if ( (ddx == 1 && ddy == 1) || (ddx == -1 && ddy == -1) )
		{ cout << (abs(dx) + abs(dy) - 2) + 1 << endl; return 0; }
	if ( (ddx == -1 && ddy == 1) || (ddx == 1 && ddy == -1) )
		{ cout << (abs(dx) + abs(dy) - 2) + 3 << endl; return 0; }
	else
		{ cout << abs(dx) + abs(dy) << endl; return 0; }
	return 0;
}