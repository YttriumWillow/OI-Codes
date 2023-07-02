// Problem:      P3368 【模板】树状数组 2
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3368
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-26 20:33:24 

// Problem:      P3258 [JLOI2014]松鼠的新家
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3258
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-26 20:22:02 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m;

template<typename Tp>
struct BIT
{
    #define N 500010
    #define lowbit(x) (x & -x)
    Tp t[N] = { 0 }; int len = 0;
    inline void init(int n) { len = n; }
    inline void add(Tp x, Tp v)
    {
        for (reg int i = x; i <= len; i += lowbit(i))
            t[i] += v;
    }
    inline void modify(Tp l, Tp r, Tp v) { add(l, v); add(r + 1, -v); }
    inline Tp query(Tp x)
    {
        reg Tp res = 0;
        for (reg int i = x; i; i -= lowbit(i))
            res += t[i];
        return res;
    }
};

BIT<int> t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; t.init(n);
	for (reg int i = 1, x; i <= n; ++i)
		cin >> x, t.modify(i, i, x);
	for (reg int i = 1, opt, l, r, k; i <= m; ++i)
	{
		cin >> opt;
		if (opt == 1)
		{
			cin >> l >> r >> k;
			t.modify(l, r, k);
		}
		else
		{
			cin >> k;
			cout << t.query(k) << endl;
		}
	}
	return 0;
}