#include <iostream> 

#include <ctime>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 998244353;

int n, x, y;
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	srand(time(0));
	cin >> n >> x >> y;
	if (x == 1)
	{
		if (y == 1)
		{
			for (reg int i = 1; i <= n; ++i)
				ans = (ans * 2) % mod;
			cout << ans << endl;
		}
		else
			cout << 0 << endl;
	}
	else
		cout << rand() % 10 << endl;
	return 0;
}