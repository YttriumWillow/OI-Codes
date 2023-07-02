#pragma GCC optimize(2)

#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e5 + 10;
const int inf = 0x7fffffff;

template<typename Tp>
struct BalancedTree // maybe really a balanced tree;
{
    vector<Tp> t; typename::vector<Tp>::iterator pos = t.begin();
    inline void getpos(Tp x) { pos = lower_bound(t.begin(), t.end(), x); }
    inline void insert(Tp x) { getpos(x); t.insert(pos, x); }
    inline void del(Tp x)    { getpos(x); t.erase(pos); }
    inline Tp queryrnk(Tp x) { getpos(x); return pos - t.begin() + 1; }
    inline Tp queryval(Tp x) { getpos(x); return t.at(x - 1); }
    inline Tp prev(Tp x)     { getpos(x); return *(--pos); }
    inline Tp next(Tp x)     { getpos(x); return *upper_bound(t.begin(), t.end(), x); }
};

BalancedTree<int> t;
int n, q, x, k, l, r;
int p[N];
char opt;

// inline void debugger(char fw)
// {
	// cerr << fw << endl;
	// for (int i = 1; i <= n; ++i)
		// cerr << p[i] << " \n"[i == n];
	// for (auto x : t.t)
		// cerr << x << ' ';
	// cerr << endl;
// }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	t.insert(-inf); t.insert(inf);
	
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> p[i], t.insert(p[i]);
	for (int i = 1; i <= q; ++i)
	{
		cin >> opt;
		if (opt == '!')
		{
			cin >> k >> x;
			// debugger('!');
			t.del(p[k]); t.insert(p[k] = x);
		}
		else
		{
			cin >> l >> r;
			// debugger('?');
			cout << t.queryrnk(r) - t.queryrnk(l - 1) + 1 << ' ';
		}
	}
	return 0;
}