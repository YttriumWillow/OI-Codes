// Problem:      P2471 [SCOI2007] 降雨量
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2471
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-17 19:19:51 

#include <iostream>

#include <cmath>
#include <unordered_map>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 50010;
const int LOG = 21;

int n, m, l, r;
int year, rain;
int y[N], w[N];
int mx, L, R;
unordered_map<int, int> mp; 

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
        Tp len = log2(r - l + 1);
        return max(st[l][len], st[r - (1 << len) + 1][len]);
    }
};

STmax<int> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> y[i] >> w[i];
	cin >> m; st.init(n, w);
	for (reg int i = 1; i <= m; ++i)
	{
		cin >> l >> r;
		if (l > r) { cout << "false" << endl; continue; }
		
		L = lower_bound(y + 1, y + n + 1, l) - y;
		R = lower_bound(y + 1, y + n + 1, r) - y;
		
		bool flgl = (y[L] == l), flgr = (y[R] == r);
		int mx = 0; L -= (!flgl); // !
		
		if (L + 1 <= R - 1) mx = st.query(L + 1, R - 1);
		
		if ( (mx >= w[L] && flgl)
		  || (w[L] < w[R] && flgl && flgr) 
		  || (mx >= w[R] && flgr) )
		  	cout << "false" << endl;
		else if (R - L != y[R] - y[L] || !flgl || !flgr)
			cout << "maybe" << endl;
		else
			cout << "true" << endl;
	}
	return 0;
}