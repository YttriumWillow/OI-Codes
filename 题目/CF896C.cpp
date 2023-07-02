// Problem:      Willem, Chtholly and Seniorious
// Contest:      Luogu
// URL:          https://www -> luogu.com.cn/problem/CF896C
// Memory Limit: 250 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-27 20:43:07 

#include <iostream>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

#include <set>
#include <vector>
#include <algorithm>
#define pb push_back

template<typename Tp>
struct ChthollyTree
{
	struct Node
	{
		Tp l, r;
		mutable Tp v;
		Node(Tp l, Tp r = 0, Tp v = 0): l(l), r(r), v(v) {}
		inline friend operator < (const Node& _x, const Node& _y)
		{ return _x.l < _y.l; }
	};
	set<Node> s;
	inline void insert(Tp pos, Tp x) { s.insert(Node(pos, pos, x)); }
	inline void init(Tp n, Tp i) { s.insert(Node(1, n, i)); }
	auto split(Tp pos)
	{
		auto it = s.lower_bound(Node(pos));
		if (it != s.end() && it->l == pos)
			return it;
		--it;
		if (it -> r < pos)
			return s.end();
		Tp l = it -> l, r = it -> r, v = it -> v;
		s.erase(it);
		s.insert(Node(l, pos - 1, v));
		return s.insert(Node(pos, r, v)).first;
	}
	inline void add(Tp l, Tp r, Tp x)
	{
		auto itr = split(r + 1), itl = split(l);
		for (auto it = itl; it != itr; ++it)
			it -> v += x;
	}
	inline void assign(Tp l, Tp r, Tp x)
	{
		auto itr = split(r + 1), itl = split(l);
		s.erase(itl, itr);
		s.insert(Node(l, r, x));
		sum += x * (r - l + 1);
	}
	
};

i64 n, m, seed, vmax;
ChthollyTree<i64> t;

i64 rnd()
{
	i64 ret = seed;
	seed = (seed * 7 + 13) % 1000000007;
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	cin >> 
	for (reg int i = 1, opt, l, r, x, y; i <= m; ++i)
	{
		
	}
	return 0;
}