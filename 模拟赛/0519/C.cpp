#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx512f,sse4.1,sse4.2,avx2")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <iostream>

#include <algorithm>

#define i64 long long
#define uint unsigned int
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 200010;
const int D = 10;

const i64 inf = 0xffffffffffffff;

int n, d;
i64 p[N][D], mx, mn;
i64 res0, res1, res2, res3;
i64 ans = -inf;

namespace Solution
{
	int mxx[110], nww[110];
	inline void subtask1()
	{
		mx = -1e15; mn = 1e15;
		for (int i = 1; i <= n; ++i)
		{
			cin >> p[i][1];
			mx = max(mx, (i64)p[i][1]);
			mn = min(mn, (i64)p[i][1]);
		}
		cout << abs(mx - mn) << endl;
	}
	inline int part(int i)
	{
		return (!!(p[i][1] < 0))
			 + ((!!(p[i][2] < 0)) << 1)
			 + ((!!(p[i][3] < 0)) << 2)
			 + ((!!(p[i][4] < 0)) << 3)
			 + ((!!(p[i][5] < 0)) << 4);
	}
	inline i64 dis(int x, int y)
	{
		i64 res = 0;
		for (int i = 1; i <= d; ++i)
			res += abs(p[x][i] - p[y][i]);
		return res;
	}
	inline void subtask2()
	{
		static int mx1, mx2, mx3, mx4;
		mx1 = mx2 = mx3 = mx4 = 1;
		static i64 now1, now2, now3, now4;
		now1 = now2 = now3 = now4 = 0;
		
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= d; ++j)
				cin >> p[i][j];
			if (p[i][1] >= 0 && p[i][2] >= 0)
			{
				if (dis(i, 0) > now1)
					now1 = dis(i, 0), mx1 = i;
			}
			if (p[i][1] < 0 && p[i][2] >= 0)
			{
				if (dis(i, 0) > now2)
					now2 = dis(i, 0), mx2 = i;
			}
			if (p[i][1] < 0 && p[i][2] < 0)
			{
				if (dis(i, 0) > now3)
					now3 = dis(i, 0), mx3 = i;
			}
			if (p[i][1] >= 0 && p[i][2] < 0)
			{
				if (dis(i, 0) > now4)
					now4 = dis(i, 0), mx4 = i;
			}
		}
		cout << max(dis(mx1, mx3), dis(mx2, mx4)) << endl;
	}
	
	
	inline void subtask3()
	{
		i64 res = 0;
		int mx[10];  fill(mx + 1, mx + 9, 1);
		i64 now[10]; fill(now + 1, now + 9, 0);
		
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= d; ++j)
				cin >> p[i][j];
			if (p[i][1] >= 0 && p[i][2] >= 0 && p[i][3] >= 0)
			{
				if (dis(i, 0) > now[0])
					now[0] = dis(i, 0), mx[0] = i;
			}
			if (p[i][1] < 0 && p[i][2] < 0 && p[i][3] < 0)
			{
				if (dis(i, 0) > now[1])
					now[1] = dis(i, 0), mx[1] = i;
			}
			if (p[i][1] < 0 && p[i][2] >= 0 && p[i][3] >= 0)
			{
				if (dis(i, 0) > now[2])
					now[2] = dis(i, 0), mx[2] = i;
			}
			if (p[i][1] >= 0 && p[i][2] < 0 && p[i][3] < 0)
			{
				if (dis(i, 0) > now[3])
					now[3] = dis(i, 0), mx[3] = i;
			}
			if (p[i][1] >= 0 && p[i][2] < 0 && p[i][3] >= 0)
			{
				if (dis(i, 0) > now[4])
					now[4] = dis(i, 0), mx[4] = i;
			}
			if (p[i][1] < 0 && p[i][2] >= 0 && p[i][3] < 0)
			{
				if (dis(i, 0) > now[5])
					now[5] = dis(i, 0), mx[5] = i;
			}
			if (p[i][1] >= 0 && p[i][2] >= 0 && p[i][3] < 0)
			{
				if (dis(i, 0) > now[6])
					now[6] = dis(i, 0), mx[6] = i;
			}
			if (p[i][1] < 0 && p[i][2] < 0 && p[i][3] >= 0)
			{
				if (dis(i, 0) > now[7])
					now[7] = dis(i, 0), mx[7] = i;
			}
		}
		for (int i = 1; i <= 8; ++i)
			res = max(res, dis(mx[i], mx[7 - i]));
		cout << res << endl;
	}
	
	
	
	
	
	
	inline void _subtask2()
	{
		i64 res = 0;
		fill(mxx, mxx + 10 + 1, 1);
		fill(nww, nww + 10 + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= d; ++j)
				cin >> p[i][j];
			if ( dis(0, i) > nww[part(i)] )
				mxx[part(i)] = i, nww[part(i)] = dis(0, i);
		}
		for (int i = 0; i <= 1; ++i)
			res = max(res, dis(mxx[i], mxx[3 - i]));
		cout << res << endl;
	}
	inline void _subtask3()
	{
		i64 res = 0;
		#define dis(i, j) (abs(p[i][1] - p[j][1]) + abs(p[i][2] - p[j][2]))
		fill(mxx, mxx + 70 + 1, 1);
		fill(nww, nww + 70 + 1, 0);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= d; ++j)
				cin >> p[i][j];
			// cerr << part(i) << endl;
			if ( dis(0, i) > nww[part(i)] )
				mxx[part(i)] = i, nww[part(i)] = dis(0, i);
		}
		for (int i = 0; i <= 3; ++i)
			res = max(res, dis(mxx[i], mxx[3 - i]));
		cout << res << endl;
	}
	
	
	
	
	
	
	
	
	inline void ___subtask2()
	{
		static int mx1, mx2, mx3, mx4;
		mx1 = mx2 = mx3 = mx4 = 1;
		static i64 now1, now2, now3, now4;
		now1 = now2 = now3 = now4 = 0;
		
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= d; ++j)
				cin >> p[i][j];
			if (p[i][1] >= 0 && p[i][2] >= 0 && p[i][3] >= 0)
			{
				if (abs(p[i][1]) + abs(p[i][2]) > now1)
					now1 = abs(p[i][1]) + abs(p[i][2]), mx1 = i;
			}
			if (p[i][1] < 0 && p[i][2] >= 0)
			{
				if (abs(p[i][1]) + abs(p[i][2]) > now2)
					now2 = abs(p[i][1]) + abs(p[i][2]), mx2 = i;
			}
			if (p[i][1] < 0 && p[i][2] < 0)
			{
				if (abs(p[i][1]) + abs(p[i][2]) > now3)
					now3 = abs(p[i][1]) + abs(p[i][2]), mx3 = i;
			}
			if (p[i][1] >= 0 && p[i][2] < 0)
			{
				if (abs(p[i][1]) + abs(p[i][2]) > now4)
					now4 = abs(p[i][1]) + abs(p[i][2]), mx4 = i;
			}
		}
		cout << max(dis(mx1, mx3), dis(mx2, mx4)) << endl;
	}
	
	inline void cheat()
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= d; ++j)
				cin >> p[i][j];
			int j;
			for (j = 1; j + 4 < i; j += 4)
			{
				res0 = res1 = res2 = res3 = 0;
				res0 += abs(p[i][1] - p[j][1]); res0 += abs(p[i][2] - p[j][2]); res0 += abs(p[i][3] - p[j][3]); res0 += abs(p[i][4] - p[j][4]); res0 += abs(p[i][5] - p[j][5]);
				res1 += abs(p[i][1] - p[j + 1][1]); res1 += abs(p[i][2] - p[j + 1][2]); res1 += abs(p[i][3] - p[j + 1][3]); res1 += abs(p[i][4] - p[j + 1][4]); res1 += abs(p[i][5] - p[j + 1][5]);
				res2 += abs(p[i][1] - p[j + 2][1]); res2 += abs(p[i][2] - p[j + 2][2]); res2 += abs(p[i][3] - p[j + 2][3]); res2 += abs(p[i][4] - p[j + 2][4]); res2 += abs(p[i][5] - p[j + 2][5]);
				res3 += abs(p[i][1] - p[j + 3][1]); res3 += abs(p[i][2] - p[j + 3][2]); res3 += abs(p[i][3] - p[j + 3][3]); res3 += abs(p[i][4] - p[j + 3][4]); res3 += abs(p[i][5] - p[j + 3][5]);
				ans = max({ans, res0, res1, res2, res3});
			}
			for (; j < i; ++j)
			{
				res0 = 0; res0 += abs(p[i][1] - p[j][1]); res0 += abs(p[i][2] - p[j][2]); res0 += abs(p[i][3] - p[j][3]); res0 += abs(p[i][4] - p[j][4]); res0 += abs(p[i][5] - p[j][5]);
				ans = max(ans, res0);
			}
		}
		cout << ans << endl;
	}
}

using namespace Solution;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> d;
	if (d == 1) subtask1();
	else if (d == 2) subtask2();
	else if (d == 3) subtask3();
	else cheat();
	
	return 0;
}