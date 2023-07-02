#include <iostream>

#include <cmath>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

bool isPrime[50000010];
longint Prime[3000010], cnt, n;

void GetPrime(longint n)
{
	for (reg int i = 1; i <= n; ++i)
        isPrime[i] = 1;
	isPrime[1] = 0;
	for (reg int i = 2; i <= n; ++i)
	{
		if (isPrime[i])
			Prime[++cnt] = i;
		for (reg int j = 1; j <= cnt && i * Prime[j] <= n; ++j) 
		{
			isPrime[i * Prime[j]] = 0;
			if (i % Prime[j] == 0) break;
		}
	}
	return;
}

int main()
{
    reg int T;
    GetPrime(50000005);
    scanf("%d", &T);
    while (T--) 
    {
        scanf("%lld", &n); bool flag = true;
        for (reg int i = 1; i <= sqrt(n); ++i)
        {
            if (n % Prime[i] == 0 && Prime[i] % 2 == 0)
            {
                flag = false;
                break;
            }
            while (n != 1 && n % Prime[i] == 0)
                n /= Prime[i];
            if (n == 1)
                break;
        }
        printf(flag ? "Yes\n" : "No\n");
    }
    // cerr << Prime[1] << endl;
    return 0;
}