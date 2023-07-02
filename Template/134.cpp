// Problem:      #134. 二维树状数组 2：区间修改，单点查询
// Contest:      LibreOJ
// URL:          https://loj.ac/p/134
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-14 19:54:40 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

template<typename Tp>
struct BIT2D
{
	#define N 4110
	#define lowbit(x) (x & -x)
	Tp t[N][N] = { 0 }; Tp n = 0, m = 0;
	inline void init(Tp ln, Tp lm) { n = ln, m = lm; }
	inline void add(Tp x, Tp y, Tp k)
	{
		for (reg int i = x; i <= n; i += lowbit(i))
			for (reg int j = y; j <= m; j += lowbit(j))
				t[i][j] += k;
	}
	inline void modify(Tp a, Tp b, Tp c, Tp d, Tp k)
	{
		add(a, b, k); add(c + 1, d + 1, k);
		add(a, d + 1, -k); add(c + 1, b, -k);
	}
	inline Tp query(Tp x, Tp y)
	{
		Tp res = 0;
		for (reg int i = x; i; i -= lowbit(i))
			for (reg int j = y; j; j -= lowbit(j))
				res += t[i][j];
		return res;
	}
};

BIT2D<i64> t;

int n, m;
int a, b, c, d;
int x, y, k, opt;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m; t.init(n, m);
	while (cin >> opt)
	{
		if (opt == 1)
		{
			cin >> a >> b >> c >> d >> k;
			t.modify(a, b, c, d, k);
		}
		else if (opt == 2)
		{
			cin >> x >> y;
			cout << t.query(x, y) << endl;
		}
		else qwq
	}
	return 0;
}