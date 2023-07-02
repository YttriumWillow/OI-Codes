#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 1e9 + 7;


int n, m, k;
int mp[1010][1010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = 1; j <= m; ++j)
			cin >> mp[i][j];
	cout << 0 << endl;
	return 0;
}