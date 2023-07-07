// Problem:      P8403 [CCC2022 J4] Good Groups
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8403
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-07 07:38:51 

#include <iostream>

#include <map>
#include <vector>
#include <cstring>
#include <unordered_map>

#define i64 long long
#define endl '\n'
#define Pii pair<int, int>
#define fir first
#define sec second
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 4e5 + 10;

int x, y, g, n;
int t1, t2, ans;
int fa[N];
int bel[N];
Pii c1[N], c2[N];
string n1, n2, n3;
unordered_map<string, int> mp;

inline void init(int n)
{
	for (int i = 1; i <= n + 1; ++i)
		fa[i] = i;
}
inline int find(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> x;
	for (int i = 1; i <= x; ++i)
	{
		cin >> n1 >> n2;
		c1[i].fir = mp[n1] ? mp[n1] : (mp[n1] = ++n);
		c1[i].sec = mp[n2] ? mp[n2] : (mp[n2] = ++n);
	}
	
	cin >> y;
	for (int i = 1; i <= y; ++i)
	{
		cin >> n1 >> n2;
		c2[i].fir = mp[n1] ? mp[n1] : (mp[n1] = ++n);
		c2[i].sec = mp[n2] ? mp[n2] : (mp[n2] = ++n);
	}
		
	cin >> g;
	for (int i = 1; i <= g; ++i)
	{
		cin >> n1 >> n2 >> n3;
		bel[mp[n1]] = i;
		bel[mp[n2]] = i;
		bel[mp[n3]] = i;
	}
	
	for (int i = 1; i <= x; ++i)
		if (bel[c1[i].fir] != bel[c1[i].sec])
			++ans;
	
	for (int i = 1; i <= y; ++i)
		if (bel[c2[i].fir] == bel[c2[i].sec])
			++ans;
	
	cout << ans << endl;
	return 0;
}