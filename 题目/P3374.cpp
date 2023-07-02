// Problem:      P3374 【模板】树状数组 1
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3374
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-26 21:03:14 

#include <iostream>

#define i64 long long 
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

template<typename Tp>
struct BIT
{
    #define N 500010
    #define lowbit(x) (x & -x)
    Tp t1[N] = { 0 };
	Tp t2[N] = { 0 };
    int len = 0;
    inline void init(int n) { len = n; }
	inline void add(Tp x, Tp v)
	{
	    for (reg int i = x; i <= len; i += lowbit(i))
	        t1[i] += v, t2[i] += x * v;
	}
	inline Tp query(Tp x)
	{
	    reg Tp res = 0;
	    for (reg int i = x; i; i -= lowbit(i))
	        res += (x + 1) * t1[i] - t2[i];
    	return res;
	}
	inline Tp range(Tp l, Tp r) { return query(r) - query(l - 1); }
	inline void modify(Tp l, Tp r, Tp x) { add(l, x); add(r + 1, -x); }
};

BIT<int> t;

int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	
	cin >> n >> m; t.init(n);
	for (reg int i = 1, x; i <= n; ++i)
		cin >> x, t.modify(i, i, x);
	for (reg int i = 1, opt, x, y; i <= m; ++i)
	{
		cin >> opt >> x >> y;
		if (opt == 1)
		{
			t.modify(x, x, y);
		}
		else
		{
			cout << t.range(x, y) << endl;
		}
	}
	return 0;
}