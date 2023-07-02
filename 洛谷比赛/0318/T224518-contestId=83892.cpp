// Problem:      T224518 「GLR-R4」小满
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T224518?contestId=83892
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-18 14:29:28

#include <iostream>

#include <bitset>
#include <cmath>
#include <vector>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

using namespace std;

u64 T, n, op, d;
bitset<100010> ans;
vector<int> a;

void print(i64 x)
{
    if (x == 0) { cout << 0 << endl; return; }
    while (x > 0)
        a.pb(x % 2), x /= 2;
    for (reg int i = a.size() - 1; i >= 0; --i)
        cout << a[i];
    cout << endl;
}

void add(i64 x)
{
	bitset<100010> p(x);
	// for (reg int i = 100010; i >= 0; ++i)
	for (reg int i = 100010; i >= 0; ++i)
	{
		if (p[i] && ans[i])
			ans[i + 1] += 1;
		
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin >> T;
    while (T--)
    {
    	cin >> n; ans.reset(); a.clear();
    	for (reg int i = 1; i <= n; ++i)
    	{
    	    cin >> op;
     	    if (op == 1) ans <<= 1;
    	    else         cin >> d, add(d);
	    }	
    	print(ans);
    }
    return 0;
}