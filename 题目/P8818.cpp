// Problem:      P8818 [CSP-S 2022] 策略游戏
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8818
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-16 20:03:32 

#include <iostream>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int LOG = 21;
const int inf = 0x7fffffff;

int n, m, q;
int lg2[N];
inline void initlog(int n)
{
	lg2[1] = 0;
	for (reg int i = 2; i <= n + 2; ++i)
		lg2[i] = lg2[i >> 1] + 1;
}
template<typename Tp>
struct STmax
{
	Tp n; Tp st[N][LOG];
	inline void init(Tp n, Tp *a)
	{
		n = n;
		for (reg int i = 1; i <= n; ++i)
			st[i][0] = a[i];
		for (reg int j = 1; (1 << j) <= n; ++j)
			for (reg int i = 1; i + (1 << j) - 1 <= n; ++i)
				st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
	inline Tp query(Tp l, Tp r)
	{
		Tp len = lg2[r - l + 1];
		return max(st[l][len], st[r - (1 << len) + 1][len]);
	}
};
template<typename Tp>
struct STmin
{
	Tp n; Tp st[N][LOG];
	inline void init(Tp n, Tp *a)
	{
		n = n;
		for (reg int i = 1; i <= n; ++i)
			st[i][0] = a[i];
		for (reg int j = 1; (1 << j) <= n; ++j)
			for (reg int i = 1; i + (1 << j) - 1 <= n; ++i)
				st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
	inline Tp query(Tp l, Tp r)
	{
		Tp len = lg2[r - l + 1];
		return min(st[l][len], st[r - (1 << len) + 1][len]);
	}
};

STmax<int> mxa, fmxa, mxb;
STmin<int> mna, zmna, mnb;
int a[N], fa[N], za[N], b[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> q; initlog(max(n, m));
	for (reg int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		fa[i] = (a[i] < 0 ? a[i] : -inf);
		za[i] = (a[i] >= 0 ? a[i] : inf);
	}
	mxa.init(n, a); mna.init(n, a);
	fmxa.init(n, fa); zmna.init(n, za);
	for (reg int i = 1; i <= m; ++i)
		cin >> b[i];
	mxb.init(m, b); mnb.init(m, b);
	
	while (q--)
	{
		int la, lb, ra, rb;
		cin >> la >> ra >> lb >> rb;
		int amx = mxa.query(la, ra);
		int amn = mna.query(la, ra);
		int famx = fmxa.query(la, ra);
		int zamn = zmna.query(la, ra);
		int bmx = mxb.query(lb, rb);
		int bmn = mnb.query(lb, rb);
		
		i64 ans = -(1ll * inf * inf);
		ans = max(ans, 1ll * amx * (amx >= 0 ? bmn : bmx));
		ans = max(ans, 1ll * amn * (amn >= 0 ? bmn : bmx));
		if (famx != -inf)
			ans = max(ans, 1ll * famx * (famx >= 0 ? bmn : bmx));
		if (zamn != inf)
			ans = max(ans, 1ll * zamn * (zamn >= 0 ? bmn : bmx));
		cout << ans << endl;
	}
	return 0;
}