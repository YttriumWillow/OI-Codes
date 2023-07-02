// Problem:      #135. 二维树状数组 3：区间修改，区间查询
// Contest:      LibreOJ
// URL:          https://loj.ac/p/135
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-14 20:04:27 

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
	Tp n, m;
	Tp v1[N][N], v2[N][N], v3[N][N], v4[N][N];
	inline void init(Tp ln, Tp lm) { n = ln, m = lm; }
	inline void add(Tp x, Tp y, Tp k)
	{
		for (reg int i = x; i <= n; i += lowbit(i))
			for (reg int j = y; j <= m; j += lowbit(j))
			{
				v1[i][j] += k;
				v2[i][j] += (x - 1) * k;
				v3[i][j] += (y - 1) * k;
				v4[i][j] += (x - 1) * (y - 1) * k;
			}
	}
	inline Tp sum(Tp x, Tp y)
	{
		Tp res = 0;
		for (reg int i = x; i; i -= lowbit(i))
			for (reg int j = y; j; j -= lowbit(j))
				res += x * y * v1[i][j] + v4[i][j]
					 - x * v3[i][j] - y * v2[i][j];
		return res;
	}
	inline void modify(Tp a, Tp b, Tp c, Tp d, Tp k)
	{
		add(a, b, k); add(c + 1, d + 1, k);
		add(a, d + 1, -k); add(c + 1, b, -k); 
	}
	inline Tp query(Tp a, Tp b, Tp c, Tp d)
	{
		return sum(c, d) + sum(a - 1, b - 1) - sum(a - 1, d) - sum(c, b - 1);
	}
};

BIT2D<i64> t;

int n, m, opt;
int a, b, c, d, k;

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
			cin >> a >> b >> c >> d;
			cout << t.query(a, b, c, d) << endl;
		}
		else qwq
	}
	return 0;
}