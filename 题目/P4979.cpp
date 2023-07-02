// Problem:      P4979 矿洞：坍塌
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4979
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-11 20:04:52 

#include <iostream>

#define i64 long long
#define reg register
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
	inline void assign(Tp l, Tp r, Tp x)
	{
		auto itr = split(r + 1), itl = split(l);
		s.erase(itl, itr);
		s.insert(Node(l, r, x));
	}
	inline bool query(Tp l, Tp r)
	{
		auto itr = split(r + 1), itl = split(l);
		for (reg auto it = itl; it != itr; ++it)
			if (it -> k != itl -> k)
				return false;
		// return true;
		if (r == n || l == 1) return 1; 
		return (--itl) -> k != (++itr) -> k;
	}
};

int main()	
{
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> c[i];
	return 0;
}