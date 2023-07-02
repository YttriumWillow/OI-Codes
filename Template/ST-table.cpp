#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int LOG = 21;

inline int read()
{
	int x = 0, sgn = 1; char ch = getchar();
	while ( ch < '0' || ch > '9' ) { if ( ch == '-' ) sgn = -1; ch = getchar(); }
	while ( ch >= '0' && ch <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( ch & 15 ); ch = getchar(); }
	return x * sgn;
}

int n, q, l, r;
int a[N];

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

STmin<int> st;

int main()
{
	// input(n)l input(a[])
	initlog(n); st.init(n, a); 
	// query
	printf("%d\n", st.query(l, r));
}