// Problem:      P3793 由乃救爷爷
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3793
// Memory Limit: 500 MB
// Time Limit:   5000 ms
// Created Time: 2023-03-30 20:50:39 

#include <iostream>

#include <cmath>
#include <algorithm>

#define i64 long long
#define u64 unsigned long long
#define reg register
#define qwq puts("fzy qwq ~");

namespace GenHelper{unsigned z1,z2,z3,z4,b;unsigned rand_(){b=((z1<<6)^z1)>>13;z1=((z1&4294967294U)<<18)^b;b=((z2<<2)^z2)>>27;z2=((z2&4294967288U)<<2)^b;b=((z3<<13)^z3)>>21;z3=((z3&4294967280U)<<7)^b;b=((z4<<3)^z4)>>12;z4=((z4&4294967168U)<<13)^b;return(z1^z2^z3^z4);}}void srand(unsigned x){using namespace GenHelper;z1=x;z2=(~x)^0x233333333U;z3=x^0x1234598766U;z4=(~x)+51;}int read(){using namespace GenHelper;int a=rand_()&32767;int b=rand_()&32767;return a*32768+b;}

using namespace std;

i64 blk, cnt;
i64 l, r, n, m, s, x;
i64 a[20000050];
i64 id[20000050];
i64 pre[850000][21];
i64 suf[850000][21];
i64 L[850000];
i64 R[850000];
i64 st[850000][21];
u64 ans;

inline void init()
{
	blk = log2(n);
	cnt = n / blk;
	if (!(n % blk)) ++cnt;
	for (reg int i = 1; i <= cnt; ++i)
	{
		L[i] = (i - 1) * blk + 1;
		R[i] = i * blk;
	}
	for (reg int i = 1; i <= n; ++i)
	{
        id[i] = (i - 1) / blk + 1;
	}
    for (reg int i = 1; i <= cnt; ++i)
    {
    	for (reg int j = 1; j <= blk; ++j)
    	{
    		pre[i][j] = max(pre[i][j - 1], a[L[i] + i - 1]);
    	}
    	for (reg int j = blk; j >= 1; --j)
    	{
    		suf[i][j] = max(suf[i][j + 1], a[R[i] - i + 1]);
    	}
    	st[i][0] = pre[i][blk];
    }
    for (reg int j = 1; ( 1 << j ) <= cnt; ++j)
		for (reg int i = 1; i + ( 1 << j ) - 1 <= n; ++i)
			st[i][j] = max(st[i][j - 1], st[i + ( 1 << j - 1 )][j - 1]);
}

inline i64 query(const i64& l, const i64& r)
{
	if (id[l] == id[r])
	{
		reg i64 res = 0;
		for (reg int i = l; i <= r; ++i)
			res = max(res, a[i]);
		return res;
	}
	else
	{
		x = log2((id[r] - 1) - (id[l] + 1) + 1);
		i64 middle = max( st[id[l]][x], st[id[r] - (1 << x) + 1][x] );
		i64 left = suf[id[l]][R[id[l]] - l + 1];
		i64 right = pre[id[r]][L[id[r]] + r - 1];
		return max( max( left, middle) , right );
	}
}

int main()
{
	cin >> n >> m >> s; srand(s);
	for (reg int i = 1; i <= n; i++)
		a[i] = read();
	init();
	
	while (m--)
	{
		l = read() % n + 1;
		r = read() % n + 1;
		if (l > r) swap(l, r);
		
		ans += query(l, r);
	}
	cout << ans << endl;
	return 0;
}