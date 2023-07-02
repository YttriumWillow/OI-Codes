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
#define endl '\n'
#define qwq puts("fzy qwq ~");

namespace GenHelper{unsigned z1,z2,z3,z4,b;unsigned rand_(){b=((z1<<6)^z1)>>13;z1=((z1&4294967294U)<<18)^b;b=((z2<<2)^z2)>>27;z2=((z2&4294967288U)<<2)^b;b=((z3<<13)^z3)>>21;z3=((z3&4294967280U)<<7)^b;b=((z4<<3)^z4)>>12;z4=((z4&4294967168U)<<13)^b;return(z1^z2^z3^z4);}}void srand(unsigned x){using namespace GenHelper;z1=x;z2=(~x)^0x233333333U;z3=x^0x1234598766U;z4=(~x)+51;}int read(){using namespace GenHelper;int a=rand_()&32767;int b=rand_()&32767;return a*32768+b;}

using namespace std;

i64 n, m, s;
i64 blk, cnt;
i64 l, r, x;
i64 L[830000];
i64 R[830000];
i64 a[20000050];
i64 id[20000050];
i64 pre[830000][25];
i64 suf[830000][25];
i64 st[830000][25];
u64 ans;

void debug()
{
	cerr << "n: " << n << "\nblk: " << blk << "\ncnt: " << cnt << endl;
	cerr << "i : "; for (reg int i = 1; i <= n; ++i) cerr << i << " \n"[i == n];
	cerr << "a : "; for (reg int i = 1; i <= n; ++i) cerr << a[i] << " \n"[i == n];
	cerr << "id: "; for (reg int i = 1; i <= n; ++i) cerr << id[i] << " \n"[i == n];
	cerr << "L : "; for (reg int i = 1; i <= cnt; ++i) cerr << L[i] << " \n"[i == cnt];
	cerr << "R : "; for (reg int i = 1; i <= cnt; ++i) cerr << R[i] << " \n"[i == cnt];
	cerr << endl;
	for (reg int i = 1; i <= cnt; ++i)
	{
    	cerr << "pre[" << i << "]: "; for (reg int j = 1; j <= blk; ++j) cerr << pre[i][j] << " ";
    	cerr << "   suf[" << i << "]: "; for (reg int j = 1; j <= blk; ++j) cerr << suf[i][j] << " \n"[j == blk];
	}
    cerr << endl;
}

void testst(int blkl, int blkr)
{
	cerr << "blk " << blkl << " : " << blkr;
	x = log2((blkl - 1) - (blkr + 1) + 1);
	cerr << " is " << max( st[blkl][x], st[blkr - (1 << x) + 1][x] ) << endl;
}

inline void init()
{
	blk = log2(n);
	cnt = n / blk;
	if (n % blk) ++cnt;
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
    		pre[i][j] = max(pre[i][j - 1], a[L[i] + j - 1]);
    	}
    	for (reg int j = blk; j >= 1; --j)
    	{
    		suf[i][j] = max(suf[i][j + 1], a[L[i] + j - 1]);
    	}
    	st[i][0] = pre[i][blk];
    }
    for (reg int j = 1; ( 1 << j ) <= cnt; ++j)
		for (reg int i = 1; i + ( 1 << j ) - 1 <= n; ++i)
			st[i][j] = max(st[i][j - 1], st[i + ( 1 << (j - 1) )][j - 1]);
}

inline i64 query(const i64& l, const i64& r)
{
	if (id[l] == id[r])
	{
		// cerr << l << " -> " << r << endl;
		reg i64 res = 0;
		for (reg int i = l; i <= r; ++i)
			res = max(res, a[i]);
		return res;
	}
	else
	{
		x = log2( (id[r] - 1) - (id[l] + 1) + 1 );
		// cerr << "x: " << x << endl;
		
		i64 middle = 0, left = 0, right = 0;
		
		// testst(id[l] + 1, id[r] - 1);
		// if (x > 0)
		middle = max( st[id[l] + 1][x], st[id[r] - 1 - (1 << x) + 1][x] );
		left  = suf[ id[l] ][ l - L[id[l]] + 1 ];
		right = pre[ id[r] ][ r - L[id[r]] + 1 ];
		
		// cerr << l << ' ' << r << endl;
		// cerr << "id: " << id[l] << " : " << id[r] << endl;
		// cerr << "" <<   left << " ";
		// cerr << " " << middle << " ";
		// cerr << " " <<  right << endl;
		// cerr << endl;
		
		return max( max( left, middle ) , right );
	}
}

int main()
{
	cin >> n >> m >> s;
	for (reg int i = 1; i <= n; i++)
		cin >> a[i];
	init();
	// debug();
	
	while (m--)
	{
		cin >> l >> r;
		// r = read() % n + 1;
		if (l > r) swap(l, r);
		
		i64 tmp = query(l, r);
		// cout << tmp << endl;
		ans += tmp;
	}
	
	cout << ans << endl;
	return 0;
}