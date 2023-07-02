#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");


#define lowbit(x) (x & -x)

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

int main()
{
	return 0;
}