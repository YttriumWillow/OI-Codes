// Problem:      P4054 [JSOI2009] 计数问题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4054
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-30 21:15:33 

// Problem:      #133. 二维树状数组 1：单点修改，区间查询
// Contest:      LibreOJ
// URL:          https://loj.ac/p/133
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-14 19:01:20 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 310;
const int COL = 110;

template<typename Tp>
struct BIT2D
{
	#define lowbit(x) (x & -x)
	Tp t[COL][N][N] = { 0 }; Tp n = 0, m = 0;
	inline void init(Tp ln, Tp lm) { n = ln, m = lm; }
	inline void modify(Tp x, Tp y, Tp k, Tp col)
	{
		for (reg int i = x; i <= n; i += lowbit(i))
			for (reg int j = y; j <= m; j += lowbit(j))
				t[col][i][j] += k;
	}
	inline Tp sum(Tp x, Tp y, Tp col)
	{
		Tp res = 0;
		for (reg int i = x; i; i -= lowbit(i))
			for (reg int j = y; j; j -= lowbit(j))
				res += t[col][i][j];
		return res;
	}
	inline Tp query(Tp x1, Tp y1, Tp x2, Tp y2, Tp col)
	{
		return sum(x2, y2, col) - sum(x1 - 1, y2, col) - sum(x2, y1 - 1, col) + sum(x1 - 1, y1 - 1, col);
	}
};

BIT2D<int> t;

int n, m, q;
int opt, x, y, col;
int x1, y1, x2, y2;
int mp[N][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m; t.init(n, m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			cin >> col;
			mp[i][j] = col;
			t.modify(i, j, 1, col);
		}
	cin >> q;
	while (q--)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> x >> y >> col;
			t.modify(x, y, -1, mp[x][y]);
			mp[x][y] = col;
			t.modify(x, y, 1, col);
		}
		else if (opt == 2)
		{
			cin >> x1 >> x2 >> y1 >> y2 >> col;
			cout << t.query(x1, y1, x2, y2, col) << endl;
		}
		else qwq
	}
	return 0;
}